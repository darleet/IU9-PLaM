public class Queen implements Comparable<Queen> {

    private final int x;
    private final int y;
    private int beatCounter;

    public Queen(int x, int y) {
        this.x = x;
        this.y = y;
        this.beatCounter = 0;
    }

    public int getX() {
        return x;
    }

    public int getY() {
        return y;
    }

    public int getBeatCounter() {
        return this.beatCounter;
    }

    public void setBeatCounter(int x) {
        this.beatCounter = x;
    }

    public int compareTo(Queen entity) {
        return Integer.compare(this.beatCounter, entity.getBeatCounter());
    }

    public String toString() {
        return "Координаты ферзя: (" + this.x + ", " + this.y + "). Бьёт "
                + this.beatCounter + " ферзей";
    }
}
