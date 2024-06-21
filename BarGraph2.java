package Package1;
import javax.swing.*;
import java.awt.*;

public class BarGraph2 extends JPanel {

    private String[] xValues;
    private int[] yValues;
    private int[] y2Values;
    private final int barWidth = 30; // Sütunların genişliği
    private final int gap; // Sütunlar arasındaki boşluk (x değerlerine göre dinamik olarak ayarlanacak)
    private final int totalBars; // Toplam sütun sayısı

    public BarGraph2(String[] xValues, int[] yValues, int[] y2Values) {
        this.xValues = xValues;
        this.yValues = yValues;
        this.y2Values = y2Values;
        this.totalBars = xValues.length * 2; // Her bir x değeri için iki sütun olduğundan, totalBars değeri iki katına çıkarıldı.
        this.gap = 50; //* (xValues.length - 1); // Sütunlar arasındaki boşluk, x değerlerinin sayısına göre hesaplanır (20 piksel olarak ayarlandı, istediğiniz değeri kullanabilirsiniz)
    }

    @Override
    protected void paintComponent(Graphics g) {
        super.paintComponent(g);
        Graphics2D g2d = (Graphics2D) g;

        // Eksenlerin çizilmesi
        g2d.drawLine(50, getHeight() - 50, getWidth() - 50, getHeight() - 50); // X eksen
        g2d.drawLine(50, getHeight() - 50, 50, 50); // Y eksen

        // X ekseni etiketleri
        for (int i = 0; i < xValues.length; i++) {
            int x = 50 + i * (barWidth * 2 + gap) + barWidth / 2; // Etiketin x konumu
            g2d.drawString((xValues[i]), x, getHeight() - 30);
        }

        // Sütunların çizilmesi
        for (int i = 0; i < totalBars / 2; i++) {
            int x1 = 50 + i * (barWidth * 2 + gap); // İlk sütunun x konumu (sütunlar arasında boşluk)
            int x2 = x1 + barWidth; // İkinci sütunun x konumu
            // Ölçekleme işlemi
            double scaleFactor;
            int maxValue = Math.max(getMaxValue(yValues), getMaxValue(y2Values));
            scaleFactor = (double) (getHeight() - 100) / maxValue; // Ölçek faktörü, panel yüksekliğinin %90'ı ile en yüksek değer arasındaki oran
            int scaledY = getHeight() - 50 - (int) (yValues[i] * scaleFactor); // Sütunların ölçeklenmiş y konumu
            int scaledY2 = getHeight() - 50 - (int) (y2Values[i] * scaleFactor); // Sütunların ölçeklenmiş y konumu
            g2d.setColor(Color.GREEN);
            g2d.fillRect(x1, scaledY, barWidth, (int) (yValues[i] * scaleFactor)); // İlk sütun
            g2d.setColor(Color.RED);
            g2d.fillRect(x2, scaledY2, barWidth, (int) (y2Values[i] * scaleFactor)); // İkinci sütun
        }

        // İşaretçilerin ve değerlerin çizilmesi
        g2d.setColor(Color.BLACK);
        for (int i = 0; i < totalBars / 2; i++) {
            int x1 = 50 + i * (barWidth * 2 + gap) + barWidth / 2; // İlk sütunun x konumu (sütunlar arasında boşluk)
            int x2 = x1 + barWidth; // İkinci sütunun x konumu
            // Ölçekleme işlemi
            double scaleFactor;
            int maxValue = Math.max(getMaxValue(yValues), getMaxValue(y2Values));
            scaleFactor = (double) (getHeight() - 100) / maxValue; // Ölçek faktörü, panel yüksekliğinin %90'ı ile en yüksek değer arasındaki oran
            int scaledY = getHeight() - 50 - (int) (yValues[i] * scaleFactor); // Sütunların ölçeklenmiş y konumu
            int scaledY2 = getHeight() - 50 - (int) (y2Values[i] * scaleFactor); // Sütunların ölçeklenmiş y konumu
            g2d.drawString("" + yValues[i] + "", x1, scaledY - 5); // İlk sütun için değer
            g2d.drawString("" + y2Values[i] + "", x2, scaledY2 - 5); // İkinci sütun için değer
        }
    }

    private int getMaxValue(int[] values) {
        int max = Integer.MIN_VALUE;
        for (int value : values) {
            if (value > max) {
                max = value;
            }
        }
        return max;
    }

    /*public static void main(String[] args) {
        int[] xValues = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12}; // Yılın 12 ayını temsil eden x değerleri
        int[] yValues = {150, 200, 250, 300, 350, 400, 450, 500, 550, 600, 650, 700}; // Örnek olarak rastgele belirlenmiş y değerleri
        int[] y2Values = {180, 220, 280, 320, 370, 420, 460, 510, 560, 610, 670, 720}; // İkinci sütun için örnek rastgele belirlenmiş y değerleri

        SwingUtilities.invokeLater(() -> {
            JFrame frame = new JFrame("Aylara Göre Sütun Grafiği");
            frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
            frame.setSize(800, 600);
            frame.add(new BarGraph(xValues, yValues, y2Values));
            frame.setVisible(true);
        });
    }*/
}
