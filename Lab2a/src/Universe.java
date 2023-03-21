public class Universe {

    private static int counter;
    private static int x, y, z;

    public Universe(){
        counter = x = y = z = 0;
    }

    private static void calcVector(Particle entity) {
        x += entity.getX();
        y += entity.getY();
        z += entity.getZ();
    }

    public static String getVector() {
        return "(" + x / counter + ", " + y / counter + ", " + z / counter + ")";
    }

    public static int getCounter() {
        return counter;
    }

    public static void addParticle(int x, int y, int z) {
        Particle new_entity = new Particle(x, y, z);
        counter++;
        calcVector(new_entity);
    }

}
