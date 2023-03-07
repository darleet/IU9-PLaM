public class Main {
    public static void main(String[] args) {
        Board myBoard = new Board();
        Queen queen1 = new Queen(5, 5);
        Queen queen2 = new Queen(6, 6);
        Queen queen3 = new Queen(1, 7);

        myBoard.addQueen(queen1);
        myBoard.addQueen(queen2);
        myBoard.addQueen(queen3);

        System.out.println("Отсортированные ферзи (метод сортировки " +
                "внутри шахматной доски):");
        myBoard.getQueens();
    }
}
