import java.util.HashSet;

public class Disjunct {
    private HashSet<String> trueVars = new HashSet<String>();
    private HashSet<String> vars = new HashSet<String>();

    public void addVar(String varName, boolean value) {
        if (value) {
            trueVars.add(varName);
        }
        vars.add(varName);
    }

    public void setVar(String varName, boolean value) {
        if (!value) {
            trueVars.remove(varName);
        } else {
            trueVars.add(varName);
        }
    }

    public boolean isTrue() {
        return trueVars.size() > 0;
    }

    @Override
    public String toString() {
        StringBuilder output = new StringBuilder("( ");
        for (String element : vars) {
            output.append(element).append(" ");
        }
        output.append(")");
        return output.toString();
    }
}
