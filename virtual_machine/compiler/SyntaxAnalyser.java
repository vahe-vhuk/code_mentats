package compiler;

import compiler.exceptions.SyntaxError;
import compiler.utils.Checker;

import java.util.ArrayList;
import java.util.Objects;

public class SyntaxAnalyser {
    private final String file_name;
    private final ArrayList<String> code;


    public SyntaxAnalyser(ArrayList<String> code, String file_name) throws Exception {
        this.code = code;
        this.file_name = file_name;
    }

    public void do_analyse() throws  SyntaxError {

        for (int line = 0; line < this.code.size(); ++line) {
            if (Objects.equals(this.code.get(line), "")) {
                continue;
            }
            Checker.save_if_flag(code.get(line));
        }

        for (int line = 0; line < this.code.size(); ++line) {
            if (! is_valid_instruction(this.code.get(line).toLowerCase())) {
                throw new SyntaxError("File " + this.file_name + ":: in line " + (line + 1));
            }
        }
    }

    private boolean is_valid_instruction(String str) {
        if (Objects.equals(str, "")) {
            return true;
        }
        if (!str.contains(" ")) {
            return Checker.is_valid_flag(str);
        }

        String[] line = str.split(" ");

        int len = line.length;

        if (len < 2 || len > 3) {
            return false;
        }

        if (len == 2) {
            return is_valid_unar_instruction(line);
        }
        return is_valid_binar_instruction(line);
    }

    private boolean is_valid_unar_instruction(String[] line) {
        if (!Checker.is_unar_instruction(line[0])) {
            return false;
        }
        if (Objects.equals(line[0],"not")) {
            return Checker.is_register(line[1]);
        }
        return Checker.is_flag(line[1]);

    }

    private boolean is_valid_binar_instruction(String[] line) {
        if (line[1].charAt(line[1].length() - 1) != ',') {
            return false;
        }
        if (!Checker.is_binar_instruction(line[0])) {
            return false;
        }
        line[1] = line[1].substring(0,line[1].length() - 1);

        boolean cond1_1 = Checker.is_address(line[1]);
        boolean cond1_2 = Checker.is_register(line[1]);
        if (!(cond1_1 || cond1_2)) {
            return false;
        }
        boolean cond2_1 = Checker.is_address(line[2]);
        boolean cond2_2 = Checker.is_all_digit(line[2]);
        boolean cond2_3 = Checker.is_register(line[2]);
        if (!(cond2_1 || cond2_2 || cond2_3)) {
            return false;
        }
        if (cond2_1 && cond2_3) {
            return true;
        }
        if (cond1_2) {
            return true;
        }
        if (cond2_1 || cond2_2) {
            return false;
        }
        return !Checker.is_all_digit(line[1]);
    }

}
