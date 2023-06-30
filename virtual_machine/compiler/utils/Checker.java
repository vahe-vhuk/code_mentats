package compiler.utils;

import java.util.ArrayList;
import java.util.Objects;

public class Checker {

    private static final String[] registers = {"ayb", "ben", "gim", "da", "ech"};
    private static final String[] unar_instructions = { "not", "jmp", "je", "jg", "jl"};
    private static final String[] binar_instructions = {"mov", "add", "sub", "mul",
                                                        "div", "and", "or", "cmp"};
    private static ArrayList<String> flags = new ArrayList<String>();


    public static boolean is_all_digit(String str) {
        try {
            int val = Integer.parseInt(str);
            return val < 128 && val >= 0;
        }
        catch (NumberFormatException e) {
            return false;
        }
    }

    public static boolean is_address(String str) {
        if (str.charAt(0) != '[' && str.charAt(str.length()-1) != ']') {
            return false;
        }
        String tmp = str.substring(1, str.length() - 1);

        return is_all_digit(tmp);
    }

    public static boolean is_register(String str) {
        for (String elem : registers) {
            if (Objects.equals(str, elem)) {
                return true;
            }
        }
        return false;
    }

    public static boolean is_unar_instruction(String str) {
        for (String elem : unar_instructions) {
            if (Objects.equals(str, elem)) {
                return true;
            }
        }
        return false;
    }

    public static boolean is_binar_instruction(String str) {
        for (String elem : binar_instructions) {
            if (Objects.equals(str, elem)) {
                return true;
            }
        }
        return false;
    }
    public static void save_if_flag(String str) {
        if (is_valid_flag(str)) {
            flags.add(str.substring(0, str.length() - 1));
        }
    }

    public static boolean is_valid_flag(String str) {
        if (!(str.charAt(str.length() - 1) == ':')) {
            return false;
        }
        String fl = str.substring(0, str.length() - 1);
        for (int i = 0; i < fl.length(); ++i) {
            if (!Character.isLetter(fl.charAt(i))) {
                return false;
            }
        }
        return true;
    }

    public static boolean is_flag(String str) {
        for (String elem : flags) {
            if (Objects.equals(str, elem)) {
                return true;
            }
        }
        return false;
    }
}
