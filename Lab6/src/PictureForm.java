import javax.swing.*;
import javax.swing.event.ChangeEvent;
import javax.swing.event.ChangeListener;

public class PictureForm {
    private JPanel mainPanel;
    private JSlider rectangleSide;
    private JSlider rotationAngle;
    private CanvasPanel canvasPanel;


    public PictureForm () {
        rotationAngle.addChangeListener(new ChangeListener() {
            @Override
            public void stateChanged(ChangeEvent changeEvent) {
                double angle = rotationAngle.getValue();
                canvasPanel.setAngle(angle);
            }
        });

        rectangleSide.addChangeListener(new ChangeListener() {
            @Override
            public void stateChanged(ChangeEvent changeEvent) {
                int side = rectangleSide.getValue();
                canvasPanel.setSize(side);
            }
        });
    }

    public static void main(String[] args) {
        JFrame frame = new JFrame("Окружность");
        frame.setContentPane(new PictureForm().mainPanel);
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        frame.pack();
        frame.setVisible(true);
    }
}
