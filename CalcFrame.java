import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JLabel;

import java.awt.Color;
import java.awt.Container;
import java.awt.Font;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.awt.event.MouseEvent;
import java.awt.event.MouseListener;

class Mycalc extends JFrame implements ActionListener, MouseListener {
    Container c;
    JLabel label = new JLabel();
    JButton btn[] = new JButton[16];
    Font fn1 = new Font("Arial", Font.BOLD, 22);
    Font fn1Hover = new Font("Arial", Font.BOLD, 26);
    Font fn2 = new Font("DigifaceWide", Font.BOLD, 22);
    String str1 = "", str2 = "", op = "";
    boolean opSelected = false;

    public Mycalc() {
        c = getContentPane();
        c.setLayout(null);
        c.setBackground(Color.DARK_GRAY);

        label.setBounds(20, 20, 255, 40);
        label.setOpaque(true);
        label.setText("0");
        label.setFont(fn2);
        label.setBackground(Color.BLACK);
        label.setForeground(Color.GREEN);
        label.setHorizontalAlignment(JLabel.RIGHT);
        c.add(label);

        int j = 1, k = 1;
        for (int i = 1; i <= 9; i++) {
            btn[i] = new JButton(String.valueOf(i));
            btn[i].setBounds(20 + (j - 1) * 65, 80 + (k - 1) * 65, 60, 60);
            btn[i].setFont(fn1);
            btn[i].setForeground(Color.WHITE);
            btn[i].setBackground(Color.BLACK);
            btn[i].setFocusPainted(false);
            btn[i].addActionListener(this);
            btn[i].addMouseListener(this);
            c.add(btn[i]);
            j++;
            if (i % 3 == 0) {
                k++;
                j = 1;
            }
        }

        btn[0] = new JButton("0");
        btn[0].setBounds(20 + (j - 1) * 65, 80 + (k - 1) * 65, 60, 60);
        btn[0].setFont(fn1);
        btn[0].setForeground(Color.WHITE);
        btn[0].setBackground(Color.BLACK);
        btn[0].setFocusPainted(false);
        btn[0].addActionListener(this);
        btn[0].addMouseListener(this);
        c.add(btn[0]);

        MakeButton("+", 10, 2, 4);
        MakeButton("-", 11, 3, 4);
        MakeButton("*", 12, 4, 2);
        MakeButton("/", 13, 4, 3);
        MakeButton("=", 14, 4, 4);
        MakeButton("C", 15, 4, 1);
    }

    public void MakeButton(String s, int i, int j, int k) {
        btn[i] = new JButton(s);
        btn[i].setBounds(20 + (j - 1) * 65, 80 + (k - 1) * 65, 60, 60);
        btn[i].setFont(fn1);
        btn[i].setBackground(new Color(0, 80, 0));
        btn[i].setForeground(Color.WHITE);
        btn[i].setFocusPainted(false);
        if (i == 14) {
            btn[i].setBackground(Color.YELLOW);
            btn[i].setForeground(Color.BLACK);
        }
        if (i == 15) {
            btn[i].setBackground(Color.RED);
            btn[i].setForeground(Color.WHITE);
        }
        c.add(btn[i]);
        btn[i].addActionListener(this);
        btn[i].addMouseListener(this);
    }

    @Override
    public void actionPerformed(ActionEvent e) {
        for (int i = 0; i <= 9; i++) {
            if (e.getSource() == btn[i]) {
                if (!opSelected) {
                    str1 += String.valueOf(i);
                    label.setText(str1);
                } else {
                    str2 += String.valueOf(i);
                    label.setText(str2);
                }
                return;
            }
        }

        if (e.getSource() == btn[10]) {
            op = "+"; opSelected = true; label.setText(str1 + " +");
        } else if (e.getSource() == btn[11]) {
            op = "-"; opSelected = true; label.setText(str1 + " -");
        } else if (e.getSource() == btn[12]) {
            op = "*"; opSelected = true; label.setText(str1 + " *");
        } else if (e.getSource() == btn[13]) {
            op = "/"; opSelected = true; label.setText(str1 + " /");
        } else if (e.getSource() == btn[15]) {
            str1 = ""; str2 = ""; op = ""; opSelected = false;
            label.setText("0");
        } else if (e.getSource() == btn[14]) {
            if (str1.isEmpty() || str2.isEmpty() || op.isEmpty()) return;
            double x = Double.parseDouble(str1);
            double y = Double.parseDouble(str2);
            double r = 0;
            switch (op) {
                case "+": r = x + y; break;
                case "-": r = x - y; break;
                case "*": r = x * y; break;
                case "/":
                    if (y == 0) { label.setText("Error"); str1 = ""; str2 = ""; op = ""; opSelected = false; return; }
                    r = x / y; break;
            }
            String result = (r == (long) r) ? String.valueOf((long) r) : String.valueOf(r);
            label.setText(result);
            str1 = result; str2 = ""; op = ""; opSelected = false;
        }
    }

    private Color getDefaultBg(JButton btn) {
        for (int i = 0; i <= 9; i++) if (this.btn[i] == btn) return Color.BLACK;
        if (btn == this.btn[14]) return Color.YELLOW;
        if (btn == this.btn[15]) return Color.RED;
        return new Color(0, 80, 0);
    }

    private Color getHoverBg(JButton btn) {
        for (int i = 0; i <= 9; i++) if (this.btn[i] == btn) return new Color(50, 50, 50);
        if (btn == this.btn[14]) return new Color(255, 220, 0);
        if (btn == this.btn[15]) return new Color(200, 0, 0);
        return new Color(0, 130, 0);
    }

    private Color getHoverFg(JButton btn) {
        if (btn == this.btn[14]) return Color.BLACK;
        return Color.WHITE;
    }

    @Override
    public void mouseEntered(MouseEvent e) {
        JButton b = (JButton) e.getSource();
        b.setFont(fn1Hover);
        b.setBackground(getHoverBg(b));
        b.setForeground(getHoverFg(b));
    }

    @Override
    public void mouseExited(MouseEvent e) {
        JButton b = (JButton) e.getSource();
        b.setFont(fn1);
        b.setBackground(getDefaultBg(b));
        if (b == this.btn[14]) b.setForeground(Color.BLACK);
        else b.setForeground(Color.WHITE);
    }

    @Override public void mouseClicked(MouseEvent e) {}
    @Override public void mousePressed(MouseEvent e) {}
    @Override public void mouseReleased(MouseEvent e) {}
}

public class CalcFrame {
    public static void main(String[] args) {
        Mycalc frm = new Mycalc();
        frm.setBounds(200, 100, 295, 450);
        frm.setVisible(true);
        frm.setTitle("My CSE Calculator");
        frm.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
    }
}