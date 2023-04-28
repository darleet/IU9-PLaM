import java.util.Objects;

public class Parser {
    private int line;

    public void parse(String[] input) throws SyntaxError {
        line = 1;
        for (String s : input) {
            int result = awaitGener(s, 1);
            if (result != s.length()) {
                throw new SyntaxError(line, result+1);
            }
            line++;
        }
    }

    private int awaitGener(String input, int col) throws SyntaxError {
        System.out.println("<Gener>");

        if (Objects.equals(input, "") || Character.isDigit(input.charAt(0))) {
            throw new SyntaxError(line, col);
        } else {
            int end = 0;
            for (char c : input.toCharArray()) {
                if (Character.isLetterOrDigit(c)) {
                    col++;
                    end++;
                } else if (c == '[' || c == ',') {
                    break;
                } else {
                    throw new SyntaxError(line, col);
                }
            }

            return awaitTail(input.substring(end), end, col);
        }
    }

    private int awaitTail(String input, int identEnd, int col) throws SyntaxError {
        System.out.println("<Tail>");
        int end = input.lastIndexOf(']');
        if (input.startsWith("[") && end != -1) {
            col++;
            awaitArgs(input.substring(1, end), col);
            return identEnd + end + 1;
        } else if (input.startsWith("[") && end == -1) {
            throw new SyntaxError(line, col);
        }
        return identEnd;
    }
    
    private void awaitArgs(String input, int col) throws SyntaxError {
        System.out.println("<Args>");
        int generEnd = awaitGener(input, col);
        awaitList(input.substring(generEnd), col+generEnd);
    }
    
    private void awaitList(String input, int col) throws SyntaxError {
        System.out.println("<List>");
        if (input.startsWith(", ")) {
            col += 2;
            awaitArgs(input.substring(2), col);
        }
    }
}
