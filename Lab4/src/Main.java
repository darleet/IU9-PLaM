public class Main {
    public static void main(String[] args) {
        Disjunct myDisjunct1 = new Disjunct();
        Disjunct myDisjunct2 = new Disjunct();

        myDisjunct1.addVar("a", false);
        myDisjunct1.addVar("b", true);

        myDisjunct2.addVar("c", false);
        myDisjunct2.addVar("d", false);

        DisjunctSet mySet = new DisjunctSet();
        mySet.addDisjunct(myDisjunct1);
        mySet.addDisjunct(myDisjunct2);

        for (Disjunct ignored : mySet) {
            System.out.println("Элемент проверен.");
        }

        System.out.println("Значение первого дизъюнкта: " + myDisjunct1.isTrue());
        System.out.println("Значение второго дизъюнкта: " + myDisjunct2.isTrue());

        myDisjunct2.setVar("a", true);

        System.out.println("Второй дизъюнкт после изменения переменной: " + myDisjunct2.isTrue());
    }
}
