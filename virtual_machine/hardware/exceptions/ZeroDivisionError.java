package hardware.exceptions;

public class ZeroDivisionError extends Exception{
    public ZeroDivisionError() {
        super("Division by zero");
    }

    public ZeroDivisionError(String message) {
        super(message);
    }
}
