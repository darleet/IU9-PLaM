public class Main {

    public static void main(String[] args) {
        System.out.println("--- Тесты ---");

        Universe.addParticle(5, -2, 7);
        Universe.addParticle(9, -6, 9);
        Universe.addParticle(-16, 4, 15);

        System.out.println("Радиус-вектор: " + Universe.getVector());
        System.out.println("Количество частиц: " + Universe.getCounter());
    }
}
