public class SyntaxError extends Exception {
    public SyntaxError(int line, int col) {
        super("syntax error at (" + line + ", " + col + ")");
    }
}
