package Package1;
import javax.swing.*;
import java.awt.*;

public class BarGraph1 extends JPanel {

    private String[] xValues;
    private int[] yValues;
    private final int barWidth = 30; // Sütunların genişliği
    private final int gap; // Sütunlar arasındaki boşluk (x değerlerine göre dinamik olarak ayarlanacak)
    private final int totalBars; // Toplam sütun sayısı

    public BarGraph1(String[] xValues, int[] yValues) {
        this.xValues = xValues;
        this.yValues = yValues;
        this.totalBars = xValues.length; // Her bir x değeri için bir sütun olduğundan, totalBars değeri xValues dizisinin uzunluğu kadar olmalıdır.
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

        // Y ekseni çizgisi
        g2d.drawLine(50, getHeight() - 50, 50, 50);

        // Sütunların çizilmesi
        for (int i = 0; i < totalBars; i++) {
            int x1 = 60 + i * (barWidth * 2 + gap); // İlk sütunun x konumu (sütunlar arasında boşluk)
            // Ölçekleme işlemi
            double scaleFactor;
            int maxValue = getMaxValue(yValues);
            scaleFactor = (double) (getHeight() - 100) / maxValue; // Ölçek faktörü, panel yüksekliğinin %90'ı ile en yüksek değer arasındaki oran
            int scaledY = getHeight() - 50 - (int) (yValues[i] * scaleFactor); // Sütunun ölçeklenmiş y konumu
            g2d.setColor(Color.BLACK);
            g2d.fillRect(x1, scaledY, barWidth, (int) (yValues[i] * scaleFactor)); // Sütun
        }

        // İşaretçilerin ve değerlerin çizilmesi
        g2d.setColor(Color.BLACK);
        for (int i = 0; i < totalBars; i++) {
            int x1 = 50 + i * (barWidth * 2 + gap) + barWidth / 2; // İlk sütunun x konumu (sütunlar arasında boşluk)
            // Ölçekleme işlemi
            double scaleFactor;
            int maxValue = getMaxValue(yValues);
            scaleFactor = (double) (getHeight() - 100) / maxValue; // Ölçek faktörü, panel yüksekliğinin %90'ı ile en yüksek değer arasındaki oran
            int scaledY = getHeight() - 50 - (int) (yValues[i] * scaleFactor); // Sütunun ölçeklenmiş y konumu
            g2d.drawString("" + yValues[i] + "", x1, scaledY - 5); // Sütun için değer
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
}