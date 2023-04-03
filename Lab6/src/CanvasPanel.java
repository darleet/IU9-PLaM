import javax.swing.*;
import java.awt.*;
import java.lang.Math;
import java.util.ArrayList;

public class CanvasPanel extends JPanel {
    private Polygon hexagon;
    private Point center;
    private double angle;
    private int size;
    private ArrayList<Polygon> squares;

    public void setAngle(double angle) {
        this.angle = angle;
        repaint();
    }

    public void setSize(int size) {
        this.size = size;
        repaint();
    }

    public CanvasPanel() {
        this.center = new Point(getWidth() / 2, getHeight() / 2);
        this.angle = 0;
        this.size = 100;
        this.hexagon = createHexagon(center, size);
        this.squares = createSquares(hexagon, size);
    }

    @Override
    protected void paintComponent(Graphics g) {
        super.paintComponent(g);
        center = new Point(getWidth() / 2, getHeight() / 2);
        hexagon = createHexagon(center, size);
        squares = createSquares(hexagon, size);
        g.setColor(Color.BLACK);
        g.drawPolygon(hexagon);
        for (Polygon square : squares) {
            g.drawPolygon(square);
        }
    }

    private Polygon createHexagon(Point center, int size) {
        Polygon hexagon = new Polygon();
        for (int i = 0; i < 6; i++) {
            double angle_deg = 60 * i + angle;
            double angle_rad = Math.PI / 180 * angle_deg;
            int x = (int) (center.x + size * Math.cos(angle_rad));
            int y = (int) (center.y + size * Math.sin(angle_rad));
            hexagon.addPoint(x, y);
        }
        return hexagon;
    }

    private ArrayList<Polygon> createSquares(Polygon hexagon, int size) {
        ArrayList<Polygon> squares = new ArrayList<>();
        for (int i = 0; i < 6; i++) {
            Point p1 = new Point(hexagon.xpoints[i], hexagon.ypoints[i]);
            Point p2 = new Point(hexagon.xpoints[(i + 1) % 6], hexagon.ypoints[(i + 1) % 6]);
            Point diff = new Point(p2.x - p1.x, p2.y - p1.y);
            double angle_rad = Math.atan2(diff.y, diff.x);
            double x_offset = size * Math.sin(angle_rad);
            double y_offset = size * Math.cos(angle_rad);
            Point sq_p1 = new Point((int) (p1.x + x_offset), (int) (p1.y - y_offset));
            Point sq_p2 = new Point((int) (p2.x + x_offset), (int) (p2.y - y_offset));
            Point sq_p3 = new Point(p2.x, p2.y);
            Point sq_p4 = new Point(p1.x, p1.y);
            Polygon square = new Polygon();
            square.addPoint(sq_p1.x, sq_p1.y);
            square.addPoint(sq_p2.x, sq_p2.y);
            square.addPoint(sq_p3.x, sq_p3.y);
            square.addPoint(sq_p4.x, sq_p4.y);
            squares.add(square);
        }
        return squares;
    }

}

