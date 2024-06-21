package Package1;

import java.awt.Color;
import java.awt.Component;
import java.awt.Font;

import javax.swing.JLabel;
import javax.swing.JTable;
import javax.swing.SwingConstants;
import javax.swing.table.DefaultTableCellRenderer;

class CustomCellRenderer extends DefaultTableCellRenderer {
    public Component getTableCellRendererComponent(JTable table, Object value,
                                                   boolean isSelected, boolean hasFocus,
                                                   int row, int column) {
        Component cell = super.getTableCellRendererComponent(table, value, isSelected, hasFocus, row, column);
        Font font = new Font("Arial Unicode MS", Font.PLAIN, 16); // Unicode sembollerini destekleyen bir font seçin
        this.setHorizontalAlignment(SwingConstants.CENTER);
        this.setFont(font);
        // Belirli bir koşula göre satırın rengini ayarla
        double currentPrice = (double) table.getValueAt(row, 3); // Güncel fiyat sütunu
        double startingPrice = (double) table.getValueAt(row, 2); // Başlangıç fiyatı sütunu
        if (currentPrice > startingPrice) {
            cell.setBackground(Color.black);
            cell.setForeground(Color.red);
            table.setValueAt("▲", row, 0);

        } else if(currentPrice< startingPrice) {
             // Unicode değeri U+1F627 olan sembol
            table.setValueAt("▼", row, 0); // Sembolü hücreye atama
            cell.setBackground(Color.black);
            cell.setForeground(Color.green);
        }else {
            table.setValueAt("⮂", row, 0); // Sembolü hücreye atama
            cell.setBackground(Color.black);
            cell.setForeground(Color.white);
        }

        return cell;
    }
}
