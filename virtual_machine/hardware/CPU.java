package hardware;

import java.util.HashMap;
import java.util.stream.Collectors;
import java.util.stream.Stream;

public class CPU {
    private RAM ram;

    private byte ayb = 0;
    private byte ben = 0;
    private byte gim = 0;
    private byte da = 0;
    private byte ech = 0;
    private byte za = 0;
    private byte gh = 0;

    private final HashMap<Byte, String> instruction_map = (HashMap<Byte, String>) Stream.of(new Object[][] {
            {(byte)0, "mov"},
            {(byte)1, "add"},
            {(byte)2, "sub"},
            {(byte)3, "mul"},
            {(byte)4, "div"},
            {(byte)5, "and"},
            {(byte)6, "or"},
            {(byte)7, "not"},
            {(byte)8, "cmp"},
            {(byte)9, "jmp"},
            {(byte)10, "gh"},
            {(byte)11, "gl"},
            {(byte)12, "ge"},
    }).collect(Collectors.toMap(data->(Byte)data[0], data->(String)data[1]));

    private final HashMap<Byte, String> register_map = (HashMap<Byte, String>) Stream.of(new Object[][] {
            {(byte)32, "ayb"},
            {(byte)33, "ben"},
            {(byte)34, "gim"},
            {(byte)35, "da"},
            {(byte)36, "ech"},
    }).collect(Collectors.toMap(data->(Byte)data[0], data->(String)data[1]));

    public CPU() {

    }

    public void connect_to_ram(RAM ram) {
        this.ram = ram;
    }

    public void run() {

    }

    private int get_code_size() {
        int size = 0;
        while (!(ram.get(size) == 0 && ram.get(size + 1) == 0 && ram.get(size + 2) == 0)) {
            size += 3;
        }

        return size + 3;
    }
}
