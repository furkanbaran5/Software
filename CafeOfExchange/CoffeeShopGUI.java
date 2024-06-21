package Package1;

import javax.swing.*;
import javax.swing.table.DefaultTableCellRenderer;
import javax.swing.table.DefaultTableModel;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.sql.SQLException;
import java.util.Hashtable;
import java.util.Timer;
import java.util.TimerTask;

public class CoffeeShopGUI extends JFrame {
    private DefaultTableModel model;
    static CoffeeDatabase coffeeDatabase = new CoffeeDatabase();
    static Hashtable<String, Coffee> coffees;
    Toolkit toolkit = Toolkit.getDefaultToolkit();

    Dimension screenSize = toolkit.getScreenSize();

    public CoffeeShopGUI() {
        setTitle("Kahve Dükkanı");
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        setSize(600, 400);

        JPanel contentPanel = new JPanel(new BorderLayout());
        contentPanel.setBackground(Color.BLACK);
        setContentPane(contentPanel);

        model = new DefaultTableModel() {
            @Override
            public boolean isCellEditable(int row, int column) {
                return false;
            }
        };

        model.addColumn("  ");
        model.addColumn("Kahve İsmi");
        model.addColumn("Başlangıç Fiyatı");
        model.addColumn("Güncel Fiyat");

        try {
            coffees = coffeeDatabase.getCoffees();
            updateTableModel(); // İlk başlatmada modeli güncelle
        } catch (SQLException e) {
            e.printStackTrace();
        }

        JTable table = new JTable(model);
        table.getColumnModel().getColumn(0).setPreferredWidth(1);
        table.setRowHeight(100);
        DefaultTableCellRenderer centerRenderer = new DefaultTableCellRenderer();
        centerRenderer.setHorizontalAlignment(SwingConstants.CENTER);
        for (int i = 0; i < table.getColumnCount(); i++) {
            table.getColumnModel().getColumn(i).setCellRenderer(new CustomCellRenderer());
        }
        for (int i = 0; i < table.getRowCount(); i++) {
            table.setRowHeight(i, (screenSize.height - screenSize.height / 22) / coffees.size());
        }

        table.setShowGrid(false);
        table.getTableHeader().setBackground(Color.black);
        table.getTableHeader().setForeground(Color.WHITE);
        table.setBackground(Color.BLACK);

        JScrollPane scrollPane = new JScrollPane(table);
        contentPanel.add(scrollPane, BorderLayout.CENTER);

        JButton addButton = new JButton("Yeni Kahve Ekle");
        addButton.setBackground(Color.gray);
        addButton.setForeground(Color.WHITE);
        addButton.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                model.addRow(new Object[]{"", "", 0.0, 0.0, ""});
            }
        });

        Timer timer = new Timer();
        timer.scheduleAtFixedRate(new UpdateTask(), 0, 5000); // 5 saniyede bir güncelleme yap

        this.setResizable(true);
        this.setSize(650, 540);
    }

    class UpdateTask extends TimerTask {
        @Override
        public void run() {
            try {
                coffees = coffeeDatabase.getCoffees();
                updateTableModel();
            } catch (SQLException e) {
                e.printStackTrace();
            }
        }
    }

    private void updateTableModel() {
        model.setRowCount(0); // Önceki satırları kaldır
        coffees.forEach((String, coffee) -> {
            model.addRow(new Object[]{" - ", coffee.getName(), coffee.getFirstPrice(), coffee.getCurrentPrice()});
        });
    }

    public static void main(String[] args) {
        SwingUtilities.invokeLater(new Runnable() {
            public void run() {
                CoffeeShopGUI gui = new CoffeeShopGUI();
                gui.setExtendedState(JFrame.MAXIMIZED_BOTH);
                gui.setResizable(false);
                gui.setVisible(true);
            }
        });
    }
}
