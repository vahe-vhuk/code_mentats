package compiler.exceptions;

public class SyntaxError extends Exception {
    public SyntaxError() {
        super("Invalid Syntax");
    }

    public  SyntaxError(String message) {
        super(message);
    }
}
