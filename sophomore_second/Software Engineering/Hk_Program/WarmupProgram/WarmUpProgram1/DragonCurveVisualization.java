import javax.swing.*;
import java.awt.*;
import java.awt.geom.Line2D;
import java.util.ArrayList;
import java.util.List;

public class DragonCurveVisualization extends JPanel {
    private static final int SIZE = 800;
    private static final double START_X = SIZE / 2;
    private static final double START_Y = SIZE / 2;
    private static final double LENGTH = 5;
    private List<Line2D.Double> lines = new ArrayList<>();

    public DragonCurveVisualization(int order) {
        setPreferredSize(new Dimension(SIZE, SIZE));
        setBackground(Color.white);
        createDragonCurve(order);
    }

    private void createDragonCurve(int order) {
        String instructions = dragonCurveInstructions(order);
        double x = START_X, y = START_Y;
        double angle = 0; // Start angle

        for (char ch : instructions.toCharArray()) {
            switch (ch) {
                case 'F':
                    double endX = x + LENGTH * Math.cos(angle);
                    double endY = y + LENGTH * Math.sin(angle);
                    lines.add(new Line2D.Double(x, y, endX, endY));
                    x = endX;
                    y = endY;
                    break;
                case 'L':
                    angle -= Math.PI / 2;
                    break;
                case 'R':
                    angle += Math.PI / 2;
                    break;
            }
        }
    }

    @Override
    protected void paintComponent(Graphics g) {
        super.paintComponent(g);
        Graphics2D g2 = (Graphics2D) g;
        g2.setColor(Color.black);
        g2.setStroke(new BasicStroke(1));
        for (Line2D.Double line : lines) {
            g2.draw(line);
        }
    }

    public static String dragonCurveInstructions(int N) {
        if (N == 0) return "F";
        String curveNMinus1 = dragonCurveInstructions(N - 1);
        String reverseCurveNMinus1 = reverseCurveInstructions(curveNMinus1);
        return curveNMinus1 + "L" + reverseCurveNMinus1;
    }

    public static String reverseCurveInstructions(String instructions) {
        StringBuilder reverse = new StringBuilder();
        for (int i = instructions.length() - 1; i >= 0; i--) {
            char ch = instructions.charAt(i);
            if (ch == 'L') reverse.append('R');
            else if (ch == 'R') reverse.append('L');
            else reverse.append(ch);
        }
        return reverse.toString();
    }

    public static void main(String[] args) {
        SwingUtilities.invokeLater(() -> {
            JFrame frame = new JFrame("Dragon Curve Visualization");
            frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
            frame.add(new DragonCurveVisualization(12)); // Change the order here
            frame.pack();
            frame.setLocationRelativeTo(null);
            frame.setVisible(true);
        });
    }
}