package compiler.exceptions;

public class NotAJassemblyFileError extends Exception {
    NotAJassemblyFileError() {
        super("Not a jassembly file");
    }

    public NotAJassemblyFileError(String message) {
        super(message);
    }
}
