package hardware.exceptions;

public class SegmentationFaultError extends Exception{
    public SegmentationFaultError() {
        super("Unacceptable memory");
    }

    public SegmentationFaultError(String message) {
        super(message);
    }
}
