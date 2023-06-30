package hardware.exceptions;

public class LoadError  extends Exception{
    public LoadError() {
        super("Not enough memory in ram");
    }

    public LoadError(String message) {
        super(message);
    }
}
