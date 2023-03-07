import java.util.ArrayList;
import java.util.Collections;

import static java.lang.Math.abs;

public class Board {

    private ArrayList<Queen> queens = new ArrayList<>();
    private int elemCounter;

    private void countBeats() {
        for(int i = 0; i < this.elemCounter; i++) {
            Queen queen1 = this.queens.get(i);
            int x1 = queen1.getX();
            int y1 = queen1.getY();

            for (int j = i; j < this.elemCounter; j++) {
                Queen queen2 = this.queens.get(j);
                int x2 = queen2.getX();
                int y2 = queen2.getY();
                if (x1 == x2 || y1 == y2 || abs(x1 - x2) == abs(y1 - y2)) {
                    queen1.setBeatCounter(queen1.getBeatCounter() + 1);
                    queen2.setBeatCounter(queen2.getBeatCounter() + 1);
                }
            }
        }
    }


    public void addQueen(Queen entity) {
        this.queens.add(entity);
        this.elemCounter++;
    }

    public void getQueens() {
        countBeats();
        Collections.sort(this.queens);
        for(int i = 0; i < this.elemCounter; i++) {
            System.out.println(this.queens.get(i));
        }
    }

}
