public class Vector {
    private double x, y, z;

    public double getX() {
        return this.x;
    }

    public double getY() {
        return this.y;
    }

    public double getZ() {
        return this.z;
    }

    public String printVector() {
        return "(" + this.x + ", " + this.y + ", " + this.z + ")";
    }

    public Vector(double x, double y, double z) {
        this.x = x;
        this.y = y;
        this.z = z;
    }

    public double scalarProd(Vector b) {
        return this.x * b.x + this.y * b.y + this.z * b.z;
    }

    public Vector vectorProd(Vector b) {
        double i = this.y * b.z - this.z * b.y;
        double j = this.z * b.x - this.x * b.z;
        double k = this.x * b.y - this.y * b.x;
        return new Vector(i, j, k);
    }

    public boolean isOrthogonal(Vector b) {
        return this.scalarProd(b) == 0;
    }

}
