public class Main {

    public static void main(String[] args) {
        Vector a = new Vector(2, 3, 5);
        Vector b = new Vector(6, 3, 4);

        double scProd = a.scalarProd(b);
        System.out.println("Скалярное произведение двух векторов: " + scProd + "\n");

        Vector vProd = a.vectorProd(b);
        System.out.println("Координаты вектора, полученного векторным произведением:" + vProd.printVector() + "\n");
        System.out.println("Координата x: " + vProd.getX());
        System.out.println("Координата y: " + vProd.getY());
        System.out.println("Координата z: " + vProd.getZ());

        boolean isOrth = a.isOrthogonal(b);
        if (isOrth) {
            System.out.println("\nВекторы ортогональны.");
        } else {
            System.out.println("\nВекторы не ортогональны.");
        }
    }

}
