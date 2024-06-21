package Package1;

import java.awt.BorderLayout;
import java.awt.event.WindowAdapter;
import java.awt.event.WindowEvent;
import java.sql.SQLException;
import java.time.LocalDate;
import java.util.Hashtable;
import javax.swing.JFrame;
import javax.swing.JPanel;
import javax.swing.SwingUtilities;
import javax.swing.GroupLayout.Alignment;
import javax.swing.GroupLayout;
import javax.swing.LayoutStyle.ComponentPlacement;
import javax.swing.JTextField;
import javax.swing.JComboBox;
import javax.swing.JButton;
import java.awt.GridLayout;
import java.awt.event.ActionListener;
import java.awt.event.ActionEvent;
import java.awt.Color;
import java.awt.Font;
import javax.swing.JLabel;
import javax.swing.JOptionPane;

public class yonetimGUI extends javax.swing.JFrame {
	
    static CoffeeDatabase coffeeDatabase = new CoffeeDatabase();
	static Hashtable<String,Person> staffs;
	static Hashtable<String,Coffee> coffees;
	static double[][] incomes = new double[8][12];
	static double[][] expense = new double[8][12];
	int monthValue = LocalDate.now().getMonthValue();
	int yearValue = LocalDate.now().getYear();
    String[] stringOfCoffee = new String[coffees.size()];
    int i=0; 	
    Management man = new Management();
    
    public yonetimGUI() {
    	this.setResizable(false);
        initComponents();
        
        addWindowListener(new WindowAdapter() {
            @Override
            public void windowClosing(WindowEvent e) {
                try {
					coffeeDatabase.updateInventory(coffees);
					coffeeDatabase.updateStaffs(staffs);
					coffeeDatabase.updateExpense(expense);
				} catch (SQLException e1) {
					e1.printStackTrace();
				}
                
            }
        });
    }

    
   
    @SuppressWarnings("unchecked")
    // <editor-fold defaultstate="collapsed" desc="Generated Code">//GEN-BEGIN:initComponents
    private void initComponents() {

        jPanel1 = new javax.swing.JPanel();
        jTabbedPane1 = new javax.swing.JTabbedPane();
        jPanel3 = new javax.swing.JPanel();
        jTabbedPane2 = new javax.swing.JTabbedPane();
        jPanel5 = new javax.swing.JPanel();
        jMaaşÖdeme = new javax.swing.JButton();
        jMaaşÖdeme.setFont(new Font("Tahoma", Font.PLAIN, 18));
        jMaaşÖdeme.addActionListener(new ActionListener() {
        	public void actionPerformed(ActionEvent e) {
        	    man.paySalary(staffs, expense);
        	    
        	    // Uyarı mesajı ekleyerek kullanıcıyı bilgilendir
        	    JOptionPane.showMessageDialog(null, "Maaşlar başarıyla ödendi!", "Uyarı", JOptionPane.INFORMATION_MESSAGE);
        	}

        });
        jPanel6 = new javax.swing.JPanel();
        jButton1 = new javax.swing.JButton();
        jButton1.setFont(new Font("Tahoma", Font.PLAIN, 18));
        jButton1.addActionListener(new ActionListener() {
        	public void actionPerformed(ActionEvent e) {
        		man.payRent(expense);
        		JOptionPane.showMessageDialog(null, "Kira başarıyla ödendi!", "Uyarı", JOptionPane.INFORMATION_MESSAGE);
        	}
        });
        jButton2 = new javax.swing.JButton();
        jButton2.setFont(new Font("Tahoma", Font.PLAIN, 18));
        jButton2.addActionListener(new ActionListener() {
        	public void actionPerformed(ActionEvent e) {
        		man.payTax(expense, incomes);
        		JOptionPane.showMessageDialog(null, "Vergi başarıyla ödendi!", "Uyarı", JOptionPane.INFORMATION_MESSAGE);
        	}
        });
        jVergiText = new javax.swing.JTextArea();
        jVergiText.setFont(new Font("Tahoma", Font.PLAIN, 18));
        jLabel2 = new javax.swing.JLabel();
        jLabel2.setFont(new Font("Tahoma", Font.PLAIN, 18));
        jLabel3 = new javax.swing.JLabel();
        jLabel3.setFont(new Font("Tahoma", Font.PLAIN, 18));
        jKiraText = new javax.swing.JTextArea();
        jKiraText.setFont(new Font("Tahoma", Font.PLAIN, 18));

        setDefaultCloseOperation(javax.swing.WindowConstants.EXIT_ON_CLOSE);

        coffees.forEach((String,coffee) -> {
        	stringOfCoffee[i]=coffee.getName();
        	i=i+1;
		});
        
        jMaaşÖdeme.setText("ÖDEME YAP");
        
        jMaaşText = new javax.swing.JTextArea();
        jMaaşText.setFont(new Font("Tahoma", Font.PLAIN, 20));
        
                jMaaşText.setColumns(20);
                jMaaşText.setRows(5);
                jMaaşText.append(" İşçi" + "\t      "+"Maaş" +"\t    "+"Bonus"+"\t    "+"Satış Sayısı"+"\n");
                staffs.forEach((String,staff) -> {
                	jMaaşText.append(" " + staff.getName() + "\t      "+ staff.getSalary() +"\t    "+ staff.getBonus()  * 0.5 +"\t    "+ staff.getBonus() +"\n");
        		});
                

        javax.swing.GroupLayout jPanel5Layout = new javax.swing.GroupLayout(jPanel5);
        jPanel5Layout.setHorizontalGroup(
        	jPanel5Layout.createParallelGroup(Alignment.LEADING)
        		.addGroup(jPanel5Layout.createSequentialGroup()
        			.addContainerGap(99, Short.MAX_VALUE)
        			.addGroup(jPanel5Layout.createParallelGroup(Alignment.LEADING)
        				.addGroup(Alignment.TRAILING, jPanel5Layout.createSequentialGroup()
        					.addComponent(jMaaşText, GroupLayout.PREFERRED_SIZE, 565, GroupLayout.PREFERRED_SIZE)
        					.addGap(90))
        				.addGroup(Alignment.TRAILING, jPanel5Layout.createSequentialGroup()
        					.addComponent(jMaaşÖdeme, GroupLayout.PREFERRED_SIZE, 278, GroupLayout.PREFERRED_SIZE)
        					.addGap(234))))
        );
        jPanel5Layout.setVerticalGroup(
        	jPanel5Layout.createParallelGroup(Alignment.LEADING)
        		.addGroup(jPanel5Layout.createSequentialGroup()
        			.addGap(55)
        			.addComponent(jMaaşText, GroupLayout.PREFERRED_SIZE, 275, GroupLayout.PREFERRED_SIZE)
        			.addGap(95)
        			.addComponent(jMaaşÖdeme, GroupLayout.PREFERRED_SIZE, 88, GroupLayout.PREFERRED_SIZE)
        			.addContainerGap(133, Short.MAX_VALUE))
        );
        jPanel5.setLayout(jPanel5Layout);

        jTabbedPane2.addTab("Maaş", jPanel5);

        jButton1.setText("Kira Öde");

        jButton2.setText("Vergi Öde");

        jVergiText.setColumns(20);
        jVergiText.setRows(5);
        jVergiText.setText(String.valueOf(incomes[yearValue-2022][monthValue-1]*0.18));
        
        jLabel2.setText("Ödenmesi gereken kira miktarı");

        jLabel3.setText("Ödenmesi gereken vergi miktarı");

        jKiraText.setColumns(20);
        jKiraText.setRows(5);
        jKiraText.setText("30000.00");
        
        javax.swing.GroupLayout jPanel6Layout = new javax.swing.GroupLayout(jPanel6);
        jPanel6Layout.setHorizontalGroup(
        	jPanel6Layout.createParallelGroup(Alignment.LEADING)
        		.addGroup(jPanel6Layout.createSequentialGroup()
        			.addGap(97)
        			.addComponent(jButton2, GroupLayout.PREFERRED_SIZE, 145, GroupLayout.PREFERRED_SIZE)
        			.addPreferredGap(ComponentPlacement.RELATED, 256, Short.MAX_VALUE)
        			.addComponent(jButton1, GroupLayout.PREFERRED_SIZE, 136, GroupLayout.PREFERRED_SIZE)
        			.addGap(120))
        		.addGroup(Alignment.TRAILING, jPanel6Layout.createSequentialGroup()
        			.addGap(59)
        			.addGroup(jPanel6Layout.createParallelGroup(Alignment.LEADING)
        				.addComponent(jLabel3, GroupLayout.PREFERRED_SIZE, 272, GroupLayout.PREFERRED_SIZE)
        				.addComponent(jVergiText, GroupLayout.PREFERRED_SIZE, 219, GroupLayout.PREFERRED_SIZE))
        			.addGap(120)
        			.addGroup(jPanel6Layout.createParallelGroup(Alignment.LEADING)
        				.addComponent(jKiraText, GroupLayout.PREFERRED_SIZE, 225, GroupLayout.PREFERRED_SIZE)
        				.addComponent(jLabel2, GroupLayout.PREFERRED_SIZE, 272, GroupLayout.PREFERRED_SIZE))
        			.addGap(31))
        );
        jPanel6Layout.setVerticalGroup(
        	jPanel6Layout.createParallelGroup(Alignment.TRAILING)
        		.addGroup(jPanel6Layout.createSequentialGroup()
        			.addGap(176)
        			.addGroup(jPanel6Layout.createParallelGroup(Alignment.BASELINE)
        				.addComponent(jLabel3)
        				.addComponent(jLabel2, GroupLayout.PREFERRED_SIZE, 22, GroupLayout.PREFERRED_SIZE))
        			.addGap(26)
        			.addGroup(jPanel6Layout.createParallelGroup(Alignment.BASELINE)
        				.addComponent(jKiraText, GroupLayout.PREFERRED_SIZE, 71, GroupLayout.PREFERRED_SIZE)
        				.addComponent(jVergiText, GroupLayout.PREFERRED_SIZE, 71, GroupLayout.PREFERRED_SIZE))
        			.addGap(83)
        			.addGroup(jPanel6Layout.createParallelGroup(Alignment.BASELINE)
        				.addComponent(jButton1, GroupLayout.PREFERRED_SIZE, 84, GroupLayout.PREFERRED_SIZE)
        				.addComponent(jButton2, GroupLayout.DEFAULT_SIZE, 78, Short.MAX_VALUE))
        			.addGap(184))
        );
        jPanel6.setLayout(jPanel6Layout);

        jTabbedPane2.addTab("Diğer Ödemeler", jPanel6);

        javax.swing.GroupLayout jPanel3Layout = new javax.swing.GroupLayout(jPanel3);
        jPanel3.setLayout(jPanel3Layout);
        jPanel3Layout.setHorizontalGroup(
            jPanel3Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGroup(jPanel3Layout.createSequentialGroup()
                .addContainerGap()
                .addComponent(jTabbedPane2)
                .addContainerGap())
        );
        jPanel3Layout.setVerticalGroup(
            jPanel3Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addComponent(jTabbedPane2, javax.swing.GroupLayout.Alignment.TRAILING)
        );

        jTabbedPane1.addTab("Ödemeler", jPanel3);

        javax.swing.GroupLayout jPanel1Layout = new javax.swing.GroupLayout(jPanel1);
        jPanel1.setLayout(jPanel1Layout);
        jPanel1Layout.setHorizontalGroup(
            jPanel1Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addComponent(jTabbedPane1, javax.swing.GroupLayout.Alignment.TRAILING)
        );
        jPanel1Layout.setVerticalGroup(
            jPanel1Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addComponent(jTabbedPane1)
        );
        
        JPanel panel = new JPanel();
        jTabbedPane1.addTab("İşletme Bilgileri", null, panel, null);
        panel.setLayout(null);
        
        btnNewButton = new JButton("Çalışan Bilgilerini Görüntüle");
        btnNewButton.addActionListener(new ActionListener() {
        	public void actionPerformed(ActionEvent e) {
        		
        		
        		i=0;
            	int[] yValues = new int[staffs.size()];
            	String[] xValues = new String[staffs.size()];
        		staffs.forEach((String,staff) -> {
        			xValues[i]=staff.getName();
        			yValues[i]=(int) staff.getBonus();
                	i=i+1;
        		});

                SwingUtilities.invokeLater(() -> {
                    JFrame frame = new JFrame("STOK");
                    frame.setDefaultCloseOperation(JFrame.DISPOSE_ON_CLOSE); // Grafik penceresinin kapatılması
                    frame.setExtendedState(JFrame.MAXIMIZED_BOTH); // Tam ekran boyutu
                    frame.getContentPane().add(new BarGraph1(xValues, yValues));

                    // Ana pencerenin kapanmasını engellemek için WindowListener ekle
                    frame.addWindowListener(new WindowAdapter() {
                        @Override
                        public void windowClosed(WindowEvent e) {
                            super.windowClosed(e);
                            // Ana pencerenin kapanmasını engellemek için burada bir işlem yapabilirsiniz.
                        }
                    });

                    frame.setVisible(true);
                });
                
                
        	}
        });
        btnNewButton.setFont(new Font("Tahoma", Font.ITALIC, 18));
        btnNewButton.setBounds(113, 425, 273, 100);
        panel.add(btnNewButton);
        
        btnNewButton_1 = new JButton("Gelir Gider Bilgileri Görüntüle");
        btnNewButton_1.addActionListener(new ActionListener() {
        	public void actionPerformed(ActionEvent e) {
        		
        		int yearChoice = Integer.parseInt(gelirGiderComboBox.getSelectedItem().toString()) - 2022;
        
        		
                String[] xValues = {"Ocak","Şubat","Mart","Nisan","Mayıs","Haziran","Temmuz","Ağustos","Eylül","Ekim","Kasım","Aralık"}; // Örneğin, ay sayıları
                int[] yValues = new int[12];
                int[] y2Values = new int[12];
                for(int i = 0; i<12; i++) {
                	
                	yValues[i] = (int)incomes[yearChoice][i];
                	y2Values[i] = (int)expense[yearChoice][i];
                } 
               
                 

                SwingUtilities.invokeLater(() -> {
                    JFrame frame = new JFrame("Gelir ve Gider Grafiği");
                    frame.setDefaultCloseOperation(JFrame.DISPOSE_ON_CLOSE); // Grafik penceresinin kapatılması
                    frame.setExtendedState(JFrame.MAXIMIZED_BOTH); // Tam ekran boyutu
                    frame.getContentPane().add(new BarGraph2(xValues, yValues, y2Values));

                    // Ana pencerenin kapanmasını engellemek için WindowListener ekle
                    frame.addWindowListener(new WindowAdapter() {
                        @Override
                        public void windowClosed(WindowEvent e) {
                            super.windowClosed(e);
                            // Ana pencerenin kapanmasını engellemek için burada bir işlem yapabilirsiniz.
                        }
                    });

                    frame.setVisible(true);
                });

        	}
        });
        btnNewButton_1.setFont(new Font("Tahoma", Font.ITALIC, 18));
        btnNewButton_1.setBounds(113, 271, 273, 100);
        panel.add(btnNewButton_1);
        
        StokDurumButton = new JButton("Stok Bilgilerini Görüntüle");
        StokDurumButton.setFont(new Font("Tahoma", Font.ITALIC, 18));
        StokDurumButton.setForeground(new Color(0, 0, 0));
        StokDurumButton.addActionListener(new ActionListener() {
        	
        	
        	
        	public void actionPerformed(ActionEvent e) {
        		i=0;
            	int[] yValues = new int[coffees.size()];
            	String[] xValues = new String[coffees.size()];
        		coffees.forEach((String,coffee) -> {
        			xValues[i]=coffee.getName();
        			yValues[i]=(int) coffee.getInventory();
                	i=i+1;
        		});

                SwingUtilities.invokeLater(() -> {
                    JFrame frame = new JFrame("STOK");
                    frame.setDefaultCloseOperation(JFrame.DISPOSE_ON_CLOSE); // Grafik penceresinin kapatılması
                    frame.setExtendedState(JFrame.MAXIMIZED_BOTH); // Tam ekran boyutu
                    frame.getContentPane().add(new BarGraph1(xValues, yValues));

                    // Ana pencerenin kapanmasını engellemek için WindowListener ekle
                    frame.addWindowListener(new WindowAdapter() {
                        @Override
                        public void windowClosed(WindowEvent e) {
                            super.windowClosed(e);
                            // Ana pencerenin kapanmasını engellemek için burada bir işlem yapabilirsiniz.
                        }
                    });

                    frame.setVisible(true);
                });
        		
        		
        	}
        });
        StokDurumButton.setBounds(113, 123, 273, 100);
        panel.add(StokDurumButton);
        
        gelirGiderComboBox = new JComboBox();
        
        
        gelirGiderComboBox.setBounds(508, 324, 173, 47);
        panel.add(gelirGiderComboBox);
        
        gelirGiderComboBox.setModel(new javax.swing.DefaultComboBoxModel<>(new String[] {"2022","2023","2024","2025","2026","2027","2028"}));
        
        JLabel lblNewLabel = new JLabel("Yıl Seçiniz\r\n:");
        lblNewLabel.setFont(new Font("Tahoma", Font.ITALIC, 21));
        lblNewLabel.setBounds(502, 271, 179, 31);
        panel.add(lblNewLabel);
        jPanelGrafik = new javax.swing.JPanel();
        jLabel1 = new javax.swing.JLabel();
        jLabel1.setFont(new Font("Tahoma", Font.PLAIN, 17));
        jSiparişBut = new javax.swing.JButton();
        jSiparişBut.setFont(new Font("Tahoma", Font.PLAIN, 20));
        jSiparişAdetField = new javax.swing.JTextField();
        
                jLabel1.setText("Sipariş etmek istediğiniz adet:");
                
                        jSiparişBut.setText("Sipariş Et");
                        jSiparişBut.addActionListener(new java.awt.event.ActionListener() {
                            public void actionPerformed(java.awt.event.ActionEvent evt) {
                                jSiparişButActionPerformed(evt);
                            }
                        });
                        
                                jSiparişAdetField.addActionListener(new java.awt.event.ActionListener() {
                                    public void actionPerformed(java.awt.event.ActionEvent evt) {
                                        jSiparişAdetFieldActionPerformed(evt);
                                    }
                                });
                                jKahveListe = new javax.swing.JList<>();
                                jKahveListe.setFont(new Font("Tahoma", Font.PLAIN, 15));
                                
                                jKahveListe.setModel(new javax.swing.AbstractListModel<String>() {
                                	String[] strings = stringOfCoffee ;
                                    public int getSize() { return strings.length; }
                                    public String getElementAt(int i) { return strings[i]; }
                                });
                                
                                        javax.swing.GroupLayout jPanelGrafikLayout = new javax.swing.GroupLayout(jPanelGrafik);
                                        jPanelGrafikLayout.setHorizontalGroup(
                                        	jPanelGrafikLayout.createParallelGroup(Alignment.LEADING)
                                        		.addGroup(jPanelGrafikLayout.createSequentialGroup()
                                        			.addGap(74)
                                        			.addComponent(jKahveListe, GroupLayout.PREFERRED_SIZE, 263, GroupLayout.PREFERRED_SIZE)
                                        			.addGap(110)
                                        			.addGroup(jPanelGrafikLayout.createParallelGroup(Alignment.LEADING, false)
                                        				.addComponent(jLabel1, GroupLayout.DEFAULT_SIZE, 243, Short.MAX_VALUE)
                                        				.addComponent(jSiparişBut, GroupLayout.PREFERRED_SIZE, 214, GroupLayout.PREFERRED_SIZE)
                                        				.addComponent(jSiparişAdetField))
                                        			.addContainerGap(89, Short.MAX_VALUE))
                                        );
                                        jPanelGrafikLayout.setVerticalGroup(
                                        	jPanelGrafikLayout.createParallelGroup(Alignment.LEADING)
                                        		.addGroup(jPanelGrafikLayout.createSequentialGroup()
                                        			.addGap(187)
                                        			.addGroup(jPanelGrafikLayout.createParallelGroup(Alignment.BASELINE)
                                        				.addGroup(jPanelGrafikLayout.createSequentialGroup()
                                        					.addComponent(jLabel1, GroupLayout.PREFERRED_SIZE, 22, GroupLayout.PREFERRED_SIZE)
                                        					.addGap(10)
                                        					.addComponent(jSiparişAdetField, GroupLayout.PREFERRED_SIZE, 50, GroupLayout.PREFERRED_SIZE)
                                        					.addPreferredGap(ComponentPlacement.RELATED, 140, Short.MAX_VALUE)
                                        					.addComponent(jSiparişBut, GroupLayout.PREFERRED_SIZE, 61, GroupLayout.PREFERRED_SIZE)
                                        					.addGap(2))
                                        				.addComponent(jKahveListe, GroupLayout.PREFERRED_SIZE, 285, GroupLayout.PREFERRED_SIZE))
                                        			.addGap(201))
                                        );
                                        jPanelGrafik.setLayout(jPanelGrafikLayout);
                                        
                                                jTabbedPane1.addTab("Stok Ekleme", jPanelGrafik);

        javax.swing.GroupLayout layout = new javax.swing.GroupLayout(getContentPane());
        getContentPane().setLayout(layout);
        layout.setHorizontalGroup(
            layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addComponent(jPanel1, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE)
        );
        layout.setVerticalGroup(
            layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addComponent(jPanel1, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE)
        );

        pack();
    }// </editor-fold>//GEN-END:initComponents

    private void jSiparişButActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_jSiparişButActionPerformed
    	
    	man.addInventory(coffees, jKahveListe.getSelectedValue(), Double.parseDouble(jSiparişAdetField.getText()), expense);
    	JOptionPane.showMessageDialog(this, "Sipariş Verildi!", "Information Massage", JOptionPane.INFORMATION_MESSAGE);
        
    }//GEN-LAST:event_jSiparişButActionPerformed

    private void jSiparişAdetFieldActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_jSiparişAdetFieldActionPerformed
        // TODO add your handling code here:
    }//GEN-LAST:event_jSiparişAdetFieldActionPerformed
    
     
    
    /**
     * @param args the command line arguments
     */
    public static void main(String args[]) {
        
        try {
            for (javax.swing.UIManager.LookAndFeelInfo info : javax.swing.UIManager.getInstalledLookAndFeels()) {
                if ("Nimbus".equals(info.getName())) {
                    javax.swing.UIManager.setLookAndFeel(info.getClassName());
                    break;
                }
            }
        } catch (ClassNotFoundException ex) {
            java.util.logging.Logger.getLogger(yonetimGUI.class.getName()).log(java.util.logging.Level.SEVERE, null, ex);
        } catch (InstantiationException ex) {
            java.util.logging.Logger.getLogger(yonetimGUI.class.getName()).log(java.util.logging.Level.SEVERE, null, ex);
        } catch (IllegalAccessException ex) {
            java.util.logging.Logger.getLogger(yonetimGUI.class.getName()).log(java.util.logging.Level.SEVERE, null, ex);
        } catch (javax.swing.UnsupportedLookAndFeelException ex) {
            java.util.logging.Logger.getLogger(yonetimGUI.class.getName()).log(java.util.logging.Level.SEVERE, null, ex);
        }
        //</editor-fold>
       
	
        
        /* Create and display the form */
        java.awt.EventQueue.invokeLater(new Runnable() {
            public void run() {
            	try {
            		
					staffs = coffeeDatabase.getStaffs();
					coffees = coffeeDatabase.getCoffees();
					incomes = coffeeDatabase.getIncomes();
					expense = coffeeDatabase.getExpense();
				} catch (SQLException e) {
					// TODO Auto-generated catch block
					e.printStackTrace();
				}
				
                new yonetimGUI().setVisible(true);
                
            }
        });
        
       
    }

    // Variables declaration - do not modify//GEN-BEGIN:variables
    private javax.swing.JButton jButton1;
    private javax.swing.JButton jButton2;
    private javax.swing.JList<String> jKahveListe;
    private javax.swing.JTextArea jKiraText;
    private javax.swing.JLabel jLabel1;
    private javax.swing.JLabel jLabel2;
    private javax.swing.JLabel jLabel3;
    private javax.swing.JTextArea jMaaşText;
    private javax.swing.JButton jMaaşÖdeme;
    private javax.swing.JPanel jPanel1;
    private javax.swing.JPanel jPanel3;
    private javax.swing.JPanel jPanel5;
    private javax.swing.JPanel jPanel6;
    private javax.swing.JPanel jPanelGrafik;
    private javax.swing.JTextField jSiparişAdetField;
    private javax.swing.JButton jSiparişBut;
    private javax.swing.JTabbedPane jTabbedPane1;
    private javax.swing.JTabbedPane jTabbedPane2;
    private javax.swing.JTextArea jVergiText;
    private JButton btnNewButton;
    private JButton btnNewButton_1;
    private JButton StokDurumButton;
    private JComboBox gelirGiderComboBox;
}