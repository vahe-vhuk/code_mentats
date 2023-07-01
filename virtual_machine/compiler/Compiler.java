package compiler;

import compiler.exceptions.NotAJassemblyFileError;
import compiler.utils.Checker;

import java.io.BufferedReader;
import java.io.File;
import java.io.FileReader;
import java.util.ArrayList;
import java.util.Objects;
import java.util.HashMap;
import java.util.stream.Collectors;
import java.util.stream.Stream;

public class Compiler {
    private final String file_name;
    private final ArrayList<String> code;
    private final ArrayList<Byte> compiled_data;

    private final HashMap<String, Byte> flag_map = new HashMap<>();

    private final HashMap<String, Byte> instruction_map = (HashMap<String, Byte>) Stream.of(new Object[][] {
            {"mov", (byte)0},
            {"add", (byte)1},
            {"sub", (byte)2},
            {"mul", (byte)3},
            {"div", (byte)4},
            {"and", (byte)5},
            {"or", (byte)6},
            {"not", (byte)7},
            {"cmp", (byte)8},
            {"jmp", (byte)9},
            {"jg", (byte)10},
            {"jl", (byte)11},
            {"je", (byte)12},
    }).collect(Collectors.toMap(data->(String)data[0], data->(Byte)data[1]));

    private final HashMap<String, Byte> register_map = (HashMap<String, Byte>) Stream.of(new Object[][] {
            {"ayb", (byte)32},
            {"ben", (byte)33},
            {"gim", (byte)34},
            {"da", (byte)35},
            {"ech", (byte)36},
    }).collect(Collectors.toMap(data->(String)data[0], data->(Byte)data[1]));

    public Compiler(String file_name) throws Exception {
        if (!(file_name.contains(".") || Objects.equals(file_name.split("\\.")[1], "jm"))) {
            throw new NotAJassemblyFileError("File " + file_name + " not a jassembly file");
        }
        this.file_name = file_name;
        this.code = new ArrayList<>();
        this.compiled_data = new ArrayList<>();


        File f = new File(file_name);
        FileReader fr = new FileReader(f);
        BufferedReader bfr = new BufferedReader(fr);

        while (bfr.ready()) {
            this.code.add(bfr.readLine());
        }
        bfr.close();

    }

    public void do_compile() throws Exception {
        preprocess();
        syntax_analyse();
        compile();

    }

    public ArrayList<Byte> get_compiled_data() {
        return this.compiled_data;
    }

    private void preprocess() {
        PreProcessor pre = new PreProcessor(this.code);

        pre.do_preprocess();
    }

    private void syntax_analyse() throws Exception {
        SyntaxAnalyser analyser = new SyntaxAnalyser(this.code, this.file_name);

        analyser.do_analyse();
    }

    private void compile() {
        for (byte i = 0; i < this.code.size(); ++i) {
            String line = this.code.get(i);
            if (Objects.equals(line, "")) {
                this.code.remove(i);
                continue;
            }
            if (Checker.is_valid_flag(line)) {
                this.flag_map.put(line.substring(0, line.length() - 1), i);
                this.code.remove(i);
            }
        }


        for (String line : this.code) {
            line = line.replace(",", "");
            this.compiled_data.addAll(encrypt(line));
        }

    }

    private ArrayList<Byte> encrypt(String str) {
        String[] line = str.split(" ");

        ArrayList<Byte> res = new ArrayList<>();
        res.add(this.instruction_map.get(line[0]));

        if (Checker.is_register(line[1])) {
            res.add(this.register_map.get(line[1]));
        }
        else  if (Checker.is_address(line[1])){
            res.add(Byte.valueOf(line[1].substring(1, line[1].length() - 1)));
        }
        else { // Checker.is_flag(line[1])
            res.add((byte)(-this.flag_map.get(line[1]) - 1));
        }
        if (line.length == 2) {
            res.add((byte) 0);
            return res;
        }

        if (Checker.is_register(line[2])) {
            res.add(this.register_map.get(line[2]));
        }
        else  if (Checker.is_address(line[2])){
            res.add(Byte.valueOf(line[2].substring(1, line[2].length() - 1)));
        }
        else { //Checker.is_all_digit(line[2])
            res.add((byte)(-Byte.valueOf(line[2]) - 1));
        }

        return res;
    }
}
