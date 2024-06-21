package proje;

import java.awt.EventQueue;
import javax.swing.JFrame;
import javax.swing.JPanel;
import javax.swing.border.EmptyBorder;
import javax.swing.JScrollPane;
import java.awt.FlowLayout;
import javax.swing.JLabel;
import java.awt.Font;
import java.awt.Color;
import javax.swing.JTabbedPane;
import javax.swing.JButton;
import java.awt.event.ActionListener;
import java.util.ArrayList;
import java.awt.event.ActionEvent;
import javax.swing.JTextField;
import javax.swing.SwingConstants;
import java.awt.SystemColor;
import javax.swing.JTextArea;
import javax.swing.JTextPane;
import javax.swing.JEditorPane;
import javax.swing.JList;
import javax.swing.JOptionPane;
import javax.swing.JComboBox;
import javax.swing.DropMode;

public class Gui extends JFrame {

	static Subscription subscription;
	static DateInfo date = new DateInfo();	
	static Distributor distributor= new Distributor();
	private static final long serialVersionUID = 1L;
	private JPanel contentPane;
	private JTextField isimtext1;
	private JTextField adrestext1;
	private JTextField kartno;
	private JTextField ccv;
	private JTextField isimtext2;
	private JTextField adrestext2;
	private JTextField ceknumara;
	private JTextField bankaismi;
	private JTextField bankakodu;
	private JTextField dergiismi1;
	private JTextField dergiisim2;
	private JTextField bireyselodemedergiismi;
	private JTextField bireyselodemeisim;
	private JTextField bireyselodemeccv;
	private JTextField bireyselodememiktari;
	

	public static void main(String[] args) {
		try {
			distributor.loadState("Kayit.txt");
		} catch (ClassNotFoundException e1) {
			e1.printStackTrace();
		}
		EventQueue.invokeLater(new Runnable() {
			public void run() {
				try {
					Gui frame = new Gui();
					frame.setVisible(true);
				} catch (Exception e) {
					e.printStackTrace();
				}
			}
		});
	}

	/**
	 * Create the frame.
	 */
	public Gui() {
		
		setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		setBounds(100, 100, 969, 865);
		contentPane = new JPanel();
		contentPane.setForeground(Color.WHITE);
		contentPane.setBackground(new Color(0, 128, 255));
		contentPane.setBorder(new EmptyBorder(5, 5, 100, 100));

		setContentPane(contentPane);
		contentPane.setLayout(null);
		
		JLabel lblNewLabel = new JLabel("FurkanExport Abonelik Sistemi");
		lblNewLabel.setBounds(234, 10, 490, 89);
		lblNewLabel.setForeground(Color.BLACK);
		lblNewLabel.setFont(new Font("Times New Roman", Font.BOLD, 35));
		contentPane.add(lblNewLabel);
		
		JTabbedPane w_tabpane = new JTabbedPane(JTabbedPane.LEFT);
		w_tabpane.setBounds(10, 158, 915, 630);
		w_tabpane.setFont(new Font("Times New Roman", Font.BOLD, 25));
		w_tabpane.setBackground(new Color(64, 0, 64));
		contentPane.add(w_tabpane);
		
		JPanel panel = new JPanel();
		panel.setForeground(new Color(0, 0, 0));
		panel.setBackground(Color.WHITE);
		w_tabpane.addTab("Giriş", null, panel, null);
		w_tabpane.setBackgroundAt(0, new Color(0, 0, 0));
		w_tabpane.setForegroundAt(0, new Color(255, 255, 255));
		panel.setLayout(null);
		
		JTextArea txtrFasfsa = new JTextArea();
		txtrFasfsa.setEditable(false);
		txtrFasfsa.setFont(new Font("Times New Roman", Font.PLAIN, 25));
		txtrFasfsa.setForeground(new Color(0, 0, 0));
		txtrFasfsa.setText("     Sistemimiz FurkanExport dergi dağıtım şirketine abone olmak \r\nve abonelerin ödeme işlemlerini sağlamaya yarar.\r\n-Bireysel müşterilerimiz \"Bireysel Abonelik\" sekmesinden abone\r\nolabilirler.\r\n-Kurumsal müşterilerimiz \"Kurumsal Abonelik\" sekmesinden abone\r\nolabilirler.\r\n-Müşterilerimiz \"Ödeme\" sekmesinden ödeme yapabilirler.\r\n-Belirli bir tarihte biten abonelikleri görüntülemek için \"Son Abonelik \r\nBilgi\" sekmesini kullanabilirsiniz.\r\n-Belirli bir yılda oluşturulan aboneliklerin ödemelerini görüntülemek\r\niçin \"Ödeme Bilgi\" sekmesini kullanabilirsiniz.\r\n-Verilerinizin işlenmesi için lütfen \"Çıkış\" butonuna basınız");
		txtrFasfsa.setBounds(0, 117, 693, 415);
		panel.add(txtrFasfsa);
		
		JLabel lblNewLabel_1 = new JLabel("Abonelik sistemine hoşgeldiniz\r\n\r\n");
		lblNewLabel_1.setHorizontalAlignment(SwingConstants.CENTER);
		lblNewLabel_1.setForeground(Color.BLACK);
		lblNewLabel_1.setFont(new Font("Times New Roman", Font.BOLD, 36));
		lblNewLabel_1.setBounds(107, 10, 478, 74);
		panel.add(lblNewLabel_1);
		
		JButton button = new JButton("New button");
		button.setBounds(238, 486, 85, 21);
		panel.add(button);
		
		JPanel panel_1 = new JPanel();
		panel_1.setBackground(Color.WHITE);
		w_tabpane.addTab("Bireysel Abonelik", null, panel_1, null);
		w_tabpane.setBackgroundAt(1, new Color(0, 0, 0));
		w_tabpane.setForegroundAt(1, new Color(255, 255, 255));
		panel_1.setLayout(null);
		
		isimtext1 = new JTextField();
		isimtext1.setFont(new Font("Times New Roman", Font.PLAIN, 25));
		isimtext1.setBackground(new Color(192, 192, 192));
		isimtext1.setBounds(153, 280, 158, 39);
		panel_1.add(isimtext1);
		isimtext1.setColumns(10);
		
		JLabel lblNewLabel_2 = new JLabel("İsim");
		lblNewLabel_2.setHorizontalAlignment(SwingConstants.LEFT);
		lblNewLabel_2.setFont(new Font("Times New Roman", Font.PLAIN, 25));
		lblNewLabel_2.setBounds(153, 241, 158, 39);
		panel_1.add(lblNewLabel_2);
		
		adrestext1 = new JTextField();
		adrestext1.setFont(new Font("Times New Roman", Font.PLAIN, 25));
		adrestext1.setColumns(10);
		adrestext1.setBackground(Color.LIGHT_GRAY);
		adrestext1.setBounds(337, 280, 158, 39);
		panel_1.add(adrestext1);
		
		JLabel lblNewLabel_2_1 = new JLabel("Adres(Şehir)");
		lblNewLabel_2_1.setHorizontalAlignment(SwingConstants.LEFT);
		lblNewLabel_2_1.setFont(new Font("Times New Roman", Font.PLAIN, 25));
		lblNewLabel_2_1.setBounds(337, 241, 158, 39);
		panel_1.add(lblNewLabel_2_1);
		
		JLabel lblNewLabel_2_2 = new JLabel("Kart No");
		lblNewLabel_2_2.setHorizontalAlignment(SwingConstants.LEFT);
		lblNewLabel_2_2.setFont(new Font("Times New Roman", Font.PLAIN, 25));
		lblNewLabel_2_2.setBounds(153, 329, 158, 39);
		panel_1.add(lblNewLabel_2_2);
		
		kartno = new JTextField();
		kartno.setFont(new Font("Times New Roman", Font.PLAIN, 25));
		kartno.setColumns(10);
		kartno.setBackground(Color.LIGHT_GRAY);
		kartno.setBounds(153, 368, 342, 39);
		panel_1.add(kartno);
		
		ccv = new JTextField();
		ccv.setFont(new Font("Times New Roman", Font.PLAIN, 25));
		ccv.setColumns(10);
		ccv.setBackground(Color.LIGHT_GRAY);
		ccv.setBounds(337, 456, 158, 39);
		panel_1.add(ccv);
		
		JLabel lblNewLabel_2_3 = new JLabel("CCV");
		lblNewLabel_2_3.setHorizontalAlignment(SwingConstants.LEFT);
		lblNewLabel_2_3.setFont(new Font("Times New Roman", Font.PLAIN, 25));
		lblNewLabel_2_3.setBounds(337, 417, 158, 39);
		panel_1.add(lblNewLabel_2_3);
		
		String arr[]= {"Ocak","Şubat","Mart","Nisan","Mayıs","Haziran","Temmuz","Ağustos","Eylül","Ekim","Kasım","Aralık"};
		JComboBox expiremonth = new JComboBox(arr);
		expiremonth.setBounds(153, 456, 72, 39);
		panel_1.add(expiremonth);
		
		JLabel lblNewLabel_2_3_1 = new JLabel("Ay");
		lblNewLabel_2_3_1.setHorizontalAlignment(SwingConstants.LEFT);
		lblNewLabel_2_3_1.setFont(new Font("Times New Roman", Font.PLAIN, 25));
		lblNewLabel_2_3_1.setBounds(153, 417, 72, 39);
		panel_1.add(lblNewLabel_2_3_1);
		
		JLabel lblNewLabel_2_3_1_1 = new JLabel("Yıl");
		lblNewLabel_2_3_1_1.setHorizontalAlignment(SwingConstants.LEFT);
		lblNewLabel_2_3_1_1.setFont(new Font("Times New Roman", Font.PLAIN, 25));
		lblNewLabel_2_3_1_1.setBounds(227, 417, 72, 39);
		panel_1.add(lblNewLabel_2_3_1_1);
		
		String arr2[]= {"2010","2011","2012","2013","2014","2015","2016","2017","2018","2019","2020","2021","2022","2023","2024","2025","2026","2027","2028","2029","2030","2031","2032","2033","2034","2035","2036","2037","2038","2039","2040"};
		JComboBox expireyear = new JComboBox(arr2);
		expireyear.setBounds(227, 456, 72, 39);
		panel_1.add(expireyear);
		
		JButton btnNewButton = new JButton("Abone Ol");
		btnNewButton.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				Individual ind1 = new Individual(isimtext1.getText(), adrestext1.getText(),kartno.getText(),expiremonth.getSelectedIndex()+1, expireyear.getSelectedIndex()+2010, Integer.parseInt(ccv.getText()));
				Journal tempJournal = distributor.searchJournal(dergiismi1.getText());	
				if(tempJournal!=null) {
					if (distributor.addSubscription(tempJournal.getName(), ind1,subscription) == true) {
						JOptionPane.showMessageDialog(btnNewButton, "Aboneliğinizin kopya sayısı arttı.");
					}else {
						subscription = new Subscription(date,1,tempJournal,ind1);
						distributor.searchJournal(dergiismi1.getText()).addSubscription(subscription);
						JOptionPane.showMessageDialog(btnNewButton, "Yeni abonelik işlemi Başarı ile Gerçekleşmiştir.");
						distributor.addSubscriber(ind1);
					}			
				}
				else {
					JOptionPane.showMessageDialog(btnNewButton, "Böyle bir dergi bulunmamaktadır.");
				}
			}
		});
		
		btnNewButton.setBackground(new Color(192, 192, 192));
		btnNewButton.setBounds(281, 505, 93, 69);
		panel_1.add(btnNewButton);
		
		JLabel lblNewLabel_2_2_2 = new JLabel("Dergi İsmi");
		lblNewLabel_2_2_2.setHorizontalAlignment(SwingConstants.LEFT);
		lblNewLabel_2_2_2.setFont(new Font("Times New Roman", Font.PLAIN, 25));
		lblNewLabel_2_2_2.setBounds(10, 73, 297, 39);
		panel_1.add(lblNewLabel_2_2_2);
		
		dergiismi1 = new JTextField();
		dergiismi1.setFont(new Font("Times New Roman", Font.PLAIN, 25));
		dergiismi1.setColumns(10);
		dergiismi1.setBackground(Color.LIGHT_GRAY);
		dergiismi1.setBounds(10, 112, 297, 39);
		panel_1.add(dergiismi1);
		
		JTextArea txtrJournalNationalGeographic_1 = new JTextArea();
		txtrJournalNationalGeographic_1.setEditable(false);
		txtrJournalNationalGeographic_1.setText("National Geographic\t3548-6245\t210₺\r\nCosmopolitan\t\t6524-9837\t250₺\r\nVogue\t\t2538-6459\t200₺\r\nModern\t\t6589-4125\t190₺\r\nTime\t\t6354-8574\t220₺\r\n\r\n\r\n\r\n\r\n\r\n");
		txtrJournalNationalGeographic_1.setFont(new Font("Times New Roman", Font.PLAIN, 16));
		txtrJournalNationalGeographic_1.setBounds(352, 94, 341, 108);
		panel_1.add(txtrJournalNationalGeographic_1);
		
		JLabel lblNewLabel_2_2_1_1_1_3 = new JLabel("Dergi");
		lblNewLabel_2_2_1_1_1_3.setHorizontalAlignment(SwingConstants.LEFT);
		lblNewLabel_2_2_1_1_1_3.setFont(new Font("Times New Roman", Font.BOLD, 25));
		lblNewLabel_2_2_1_1_1_3.setBounds(351, 55, 64, 39);
		panel_1.add(lblNewLabel_2_2_1_1_1_3);
		
		JLabel lblNewLabel_2_2_1_1_1_1_1 = new JLabel("Issn");
		lblNewLabel_2_2_1_1_1_1_1.setHorizontalAlignment(SwingConstants.LEFT);
		lblNewLabel_2_2_1_1_1_1_1.setFont(new Font("Times New Roman", Font.BOLD, 25));
		lblNewLabel_2_2_1_1_1_1_1.setBounds(533, 55, 64, 39);
		panel_1.add(lblNewLabel_2_2_1_1_1_1_1);
		
		JLabel lblNewLabel_2_2_1_1_1_2_1 = new JLabel("Fiyat");
		lblNewLabel_2_2_1_1_1_2_1.setHorizontalAlignment(SwingConstants.LEFT);
		lblNewLabel_2_2_1_1_1_2_1.setFont(new Font("Times New Roman", Font.BOLD, 25));
		lblNewLabel_2_2_1_1_1_2_1.setBounds(619, 55, 64, 39);
		panel_1.add(lblNewLabel_2_2_1_1_1_2_1);
		
		JLabel lblBireyselAbonelikSistemi = new JLabel("Bireysel Abonelik Ekranı");
		lblBireyselAbonelikSistemi.setHorizontalAlignment(SwingConstants.CENTER);
		lblBireyselAbonelikSistemi.setForeground(Color.BLACK);
		lblBireyselAbonelikSistemi.setFont(new Font("Times New Roman", Font.BOLD, 30));
		lblBireyselAbonelikSistemi.setBounds(10, 10, 673, 42);
		panel_1.add(lblBireyselAbonelikSistemi);
		
		JPanel panel_2 = new JPanel();
		panel_2.setBackground(Color.WHITE);
		w_tabpane.addTab("Kurumsal Abonelik", null, panel_2, null);
		w_tabpane.setBackgroundAt(2, new Color(0, 0, 0));
		w_tabpane.setForegroundAt(2, new Color(255, 255, 255));
		panel_2.setLayout(null);
		
		isimtext2 = new JTextField();
		isimtext2.setFont(new Font("Times New Roman", Font.PLAIN, 25));
		isimtext2.setColumns(10);
		isimtext2.setBackground(Color.LIGHT_GRAY);
		isimtext2.setBounds(0, 287, 321, 39);
		panel_2.add(isimtext2);
		
		JLabel lblNewLabel_2_4 = new JLabel("İsim");
		lblNewLabel_2_4.setHorizontalAlignment(SwingConstants.LEFT);
		lblNewLabel_2_4.setFont(new Font("Times New Roman", Font.PLAIN, 25));
		lblNewLabel_2_4.setBounds(0, 248, 321, 39);
		panel_2.add(lblNewLabel_2_4);
		
		adrestext2 = new JTextField();
		adrestext2.setFont(new Font("Times New Roman", Font.PLAIN, 25));
		adrestext2.setColumns(10);
		adrestext2.setBackground(Color.LIGHT_GRAY);
		adrestext2.setBounds(341, 287, 342, 39);
		panel_2.add(adrestext2);
		
		JLabel lblNewLabel_2_1_1 = new JLabel("Adres(Şehir)");
		lblNewLabel_2_1_1.setHorizontalAlignment(SwingConstants.LEFT);
		lblNewLabel_2_1_1.setFont(new Font("Times New Roman", Font.PLAIN, 25));
		lblNewLabel_2_1_1.setBounds(341, 248, 342, 39);
		panel_2.add(lblNewLabel_2_1_1);
		
		JLabel lblNewLabel_2_2_1 = new JLabel("Hesap Numarası");
		lblNewLabel_2_2_1.setHorizontalAlignment(SwingConstants.LEFT);
		lblNewLabel_2_2_1.setFont(new Font("Times New Roman", Font.PLAIN, 25));
		lblNewLabel_2_2_1.setBounds(0, 461, 321, 39);
		panel_2.add(lblNewLabel_2_2_1);
		
		ceknumara = new JTextField();
		ceknumara.setFont(new Font("Times New Roman", Font.PLAIN, 25));
		ceknumara.setColumns(10);
		ceknumara.setBackground(Color.LIGHT_GRAY);
		ceknumara.setBounds(0, 500, 321, 39);
		panel_2.add(ceknumara);
		
		String arr3[]= {"1","2","3","4","5","6","7","8","9","10","11","12","13","14","15","16","17","18","19","20","21","22","23","24","25","26","27","28","29","30","31"};
		JComboBox day = new JComboBox(arr3);
		day.setBounds(341, 500, 89, 39);
		panel_2.add(day);
		
		JLabel lblNewLabel_2_3_1_2 = new JLabel("Gün");
		lblNewLabel_2_3_1_2.setHorizontalAlignment(SwingConstants.LEFT);
		lblNewLabel_2_3_1_2.setFont(new Font("Times New Roman", Font.PLAIN, 25));
		lblNewLabel_2_3_1_2.setBounds(341, 461, 89, 39);
		panel_2.add(lblNewLabel_2_3_1_2);
		
		JComboBox ay = new JComboBox(arr);
		ay.setBounds(464, 500, 89, 39);
		panel_2.add(ay);
		
		JComboBox yil = new JComboBox(arr2);
		yil.setBounds(594, 500, 89, 39);
		panel_2.add(yil);
		
		
		JButton btnNewButton_1 = new JButton("Abone Ol");
		btnNewButton_1.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				Corporation corp1 = new Corporation(isimtext2.getText(), adrestext2.getText(), Integer.parseInt(bankakodu.getText()), bankaismi.getText(), day.getSelectedIndex()+1,ay.getSelectedIndex()+1 , yil.getSelectedIndex()+2010, Integer.parseInt(ceknumara.getText()));
				Journal tempJournal = distributor.searchJournal(dergiisim2.getText());
				if(tempJournal!=null) {
					if (distributor.addSubscription(tempJournal.getName(), corp1,subscription) == true) {
						JOptionPane.showMessageDialog(btnNewButton, "Aboneliğinizin kopya sayısı arttı.");
					}else {
						subscription = new Subscription(date,1,tempJournal,corp1);
						distributor.searchJournal(dergiisim2.getText()).addSubscription(subscription);
						JOptionPane.showMessageDialog(btnNewButton, "Yeni abonelik işlemi Başarı ile Gerçekleşmiştir.");
						distributor.addSubscriber(corp1);
					}			
				}
				else {
					JOptionPane.showMessageDialog(btnNewButton, "Böyle bir dergi bulunmamaktadır.");
				}
			}
		});
		
		btnNewButton_1.setBackground(Color.LIGHT_GRAY);
		btnNewButton_1.setBounds(270, 546, 153, 69);
		panel_2.add(btnNewButton_1);
		
		JLabel lblNewLabel_2_3_1_2_1 = new JLabel("Ay");
		lblNewLabel_2_3_1_2_1.setHorizontalAlignment(SwingConstants.LEFT);
		lblNewLabel_2_3_1_2_1.setFont(new Font("Times New Roman", Font.PLAIN, 25));
		lblNewLabel_2_3_1_2_1.setBounds(464, 461, 89, 39);
		panel_2.add(lblNewLabel_2_3_1_2_1);
		
		JLabel lblNewLabel_2_3_1_2_2 = new JLabel("Yıl");
		lblNewLabel_2_3_1_2_2.setHorizontalAlignment(SwingConstants.LEFT);
		lblNewLabel_2_3_1_2_2.setFont(new Font("Times New Roman", Font.PLAIN, 25));
		lblNewLabel_2_3_1_2_2.setBounds(594, 461, 89, 39);
		panel_2.add(lblNewLabel_2_3_1_2_2);
		
		JLabel lblNewLabel_2_2_1_1 = new JLabel("Çek Bilgileri");
		lblNewLabel_2_2_1_1.setHorizontalAlignment(SwingConstants.CENTER);
		lblNewLabel_2_2_1_1.setFont(new Font("Times New Roman", Font.BOLD, 25));
		lblNewLabel_2_2_1_1.setBounds(149, 423, 342, 39);
		panel_2.add(lblNewLabel_2_2_1_1);
		
		JLabel lblNewLabel_2_4_1 = new JLabel("Banka İsmi");
		lblNewLabel_2_4_1.setHorizontalAlignment(SwingConstants.LEFT);
		lblNewLabel_2_4_1.setFont(new Font("Times New Roman", Font.PLAIN, 25));
		lblNewLabel_2_4_1.setBounds(0, 336, 321, 39);
		panel_2.add(lblNewLabel_2_4_1);
		
		bankaismi = new JTextField();
		bankaismi.setFont(new Font("Times New Roman", Font.PLAIN, 25));
		bankaismi.setColumns(10);
		bankaismi.setBackground(Color.LIGHT_GRAY);
		bankaismi.setBounds(0, 374, 321, 39);
		panel_2.add(bankaismi);
		
		JLabel lblNewLabel_2_4_2 = new JLabel("Banka Kodu");
		lblNewLabel_2_4_2.setHorizontalAlignment(SwingConstants.LEFT);
		lblNewLabel_2_4_2.setFont(new Font("Times New Roman", Font.PLAIN, 25));
		lblNewLabel_2_4_2.setBounds(341, 336, 342, 39);
		panel_2.add(lblNewLabel_2_4_2);
		
		bankakodu = new JTextField();
		bankakodu.setFont(new Font("Times New Roman", Font.PLAIN, 25));
		bankakodu.setColumns(10);
		bankakodu.setBackground(Color.LIGHT_GRAY);
		bankakodu.setBounds(341, 375, 342, 39);
		panel_2.add(bankakodu);
		
		JLabel lblNewLabel_2_4_1_1 = new JLabel("Dergi İsmi");
		lblNewLabel_2_4_1_1.setHorizontalAlignment(SwingConstants.LEFT);
		lblNewLabel_2_4_1_1.setFont(new Font("Times New Roman", Font.PLAIN, 25));
		lblNewLabel_2_4_1_1.setBounds(0, 109, 321, 39);
		panel_2.add(lblNewLabel_2_4_1_1);
		
		dergiisim2 = new JTextField();
		dergiisim2.setFont(new Font("Times New Roman", Font.PLAIN, 25));
		dergiisim2.setColumns(10);
		dergiisim2.setBackground(Color.LIGHT_GRAY);
		dergiisim2.setBounds(0, 148, 321, 39);
		panel_2.add(dergiisim2);
		
		JTextArea txtrJournalNationalGeographic = new JTextArea();
		txtrJournalNationalGeographic.setEditable(false);
		txtrJournalNationalGeographic.setFont(new Font("Times New Roman", Font.PLAIN, 16));
		txtrJournalNationalGeographic.setText("National Geographic\t3548-6245\t210₺\r\nCosmopolitan\t\t6524-9837\t250₺\r\nVogue\t\t2538-6459\t200₺\r\nModern\t\t6589-4125\t190₺\r\nTime\t\t6354-8574\t220₺\r\n\r\n\r\n\r\n\r\n\r\n");
		txtrJournalNationalGeographic.setBounds(352, 114, 341, 108);
		panel_2.add(txtrJournalNationalGeographic);
		
		JLabel lblNewLabel_2_2_1_1_1 = new JLabel("Dergi");
		lblNewLabel_2_2_1_1_1.setHorizontalAlignment(SwingConstants.LEFT);
		lblNewLabel_2_2_1_1_1.setFont(new Font("Times New Roman", Font.BOLD, 25));
		lblNewLabel_2_2_1_1_1.setBounds(351, 75, 64, 39);
		panel_2.add(lblNewLabel_2_2_1_1_1);
		
		JLabel lblNewLabel_2_2_1_1_1_1 = new JLabel("Issn");
		lblNewLabel_2_2_1_1_1_1.setHorizontalAlignment(SwingConstants.LEFT);
		lblNewLabel_2_2_1_1_1_1.setFont(new Font("Times New Roman", Font.BOLD, 25));
		lblNewLabel_2_2_1_1_1_1.setBounds(533, 75, 64, 39);
		panel_2.add(lblNewLabel_2_2_1_1_1_1);
		
		JLabel lblNewLabel_2_2_1_1_1_2 = new JLabel("Fiyat");
		lblNewLabel_2_2_1_1_1_2.setHorizontalAlignment(SwingConstants.LEFT);
		lblNewLabel_2_2_1_1_1_2.setFont(new Font("Times New Roman", Font.BOLD, 25));
		lblNewLabel_2_2_1_1_1_2.setBounds(619, 75, 64, 39);
		panel_2.add(lblNewLabel_2_2_1_1_1_2);
		
		JLabel lblKurumsalAbonelikEkran = new JLabel("Kurumsal Abonelik Ekranı");
		lblKurumsalAbonelikEkran.setHorizontalAlignment(SwingConstants.CENTER);
		lblKurumsalAbonelikEkran.setForeground(Color.BLACK);
		lblKurumsalAbonelikEkran.setFont(new Font("Times New Roman", Font.BOLD, 30));
		lblKurumsalAbonelikEkran.setBounds(10, 10, 673, 42);
		panel_2.add(lblKurumsalAbonelikEkran);
		
		JPanel panel_3 = new JPanel();
		panel_3.setLayout(null);
		panel_3.setBackground(Color.WHITE);
		w_tabpane.addTab("Ödeme", null, panel_3, null);
		w_tabpane.setBackgroundAt(3, new Color(0, 0, 0));
		w_tabpane.setForegroundAt(3, new Color(255, 255, 255));
		
		JLabel lblBireyseldemeEkran = new JLabel("Ödeme Ekranı");
		lblBireyseldemeEkran.setHorizontalAlignment(SwingConstants.CENTER);
		lblBireyseldemeEkran.setForeground(Color.BLACK);
		lblBireyseldemeEkran.setFont(new Font("Times New Roman", Font.BOLD, 30));
		lblBireyseldemeEkran.setBounds(10, 10, 673, 42);
		panel_3.add(lblBireyseldemeEkran);
		
		JLabel lblNewLabel_2_2_2_1 = new JLabel("Dergi İsmi");
		lblNewLabel_2_2_2_1.setHorizontalAlignment(SwingConstants.LEFT);
		lblNewLabel_2_2_2_1.setFont(new Font("Times New Roman", Font.PLAIN, 25));
		lblNewLabel_2_2_2_1.setBounds(10, 102, 297, 39);
		panel_3.add(lblNewLabel_2_2_2_1);
		
		bireyselodemedergiismi = new JTextField();
		bireyselodemedergiismi.setFont(new Font("Times New Roman", Font.PLAIN, 25));
		bireyselodemedergiismi.setColumns(10);
		bireyselodemedergiismi.setBackground(Color.LIGHT_GRAY);
		bireyselodemedergiismi.setBounds(10, 141, 297, 39);
		panel_3.add(bireyselodemedergiismi);
		
		JLabel lblNewLabel_2_5 = new JLabel("İsim");
		lblNewLabel_2_5.setHorizontalAlignment(SwingConstants.LEFT);
		lblNewLabel_2_5.setFont(new Font("Times New Roman", Font.PLAIN, 25));
		lblNewLabel_2_5.setBounds(153, 270, 342, 39);
		panel_3.add(lblNewLabel_2_5);
		
		bireyselodemeisim = new JTextField();
		bireyselodemeisim.setFont(new Font("Times New Roman", Font.PLAIN, 25));
		bireyselodemeisim.setColumns(10);
		bireyselodemeisim.setBackground(Color.LIGHT_GRAY);
		bireyselodemeisim.setBounds(153, 309, 342, 39);
		panel_3.add(bireyselodemeisim);
		
		JLabel lblNewLabel_2_2_3 = new JLabel("Ödeme Miktarı");
		lblNewLabel_2_2_3.setHorizontalAlignment(SwingConstants.LEFT);
		lblNewLabel_2_2_3.setFont(new Font("Times New Roman", Font.PLAIN, 25));
		lblNewLabel_2_2_3.setBounds(153, 446, 158, 39);
		panel_3.add(lblNewLabel_2_2_3);
		
		bireyselodemeccv = new JTextField();
		bireyselodemeccv.setFont(new Font("Times New Roman", Font.PLAIN, 25));
		bireyselodemeccv.setColumns(10);
		bireyselodemeccv.setBackground(Color.LIGHT_GRAY);
		bireyselodemeccv.setBounds(153, 397, 342, 39);
		panel_3.add(bireyselodemeccv);
		
		bireyselodememiktari = new JTextField();
		bireyselodememiktari.setFont(new Font("Times New Roman", Font.PLAIN, 25));
		bireyselodememiktari.setColumns(10);
		bireyselodememiktari.setBackground(Color.LIGHT_GRAY);
		bireyselodememiktari.setBounds(153, 485, 342, 39);
		panel_3.add(bireyselodememiktari);
		
		JLabel lblNewLabel_2_3_2 = new JLabel("CCV(Kurumsal için Hesap No)");
		lblNewLabel_2_3_2.setHorizontalAlignment(SwingConstants.LEFT);
		lblNewLabel_2_3_2.setFont(new Font("Times New Roman", Font.PLAIN, 25));
		lblNewLabel_2_3_2.setBounds(153, 358, 342, 39);
		panel_3.add(lblNewLabel_2_3_2);
		
		JButton bireyselodemebutton = new JButton("Öde");
		bireyselodemebutton.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				int flag=0;
				Journal tempJournal = distributor.searchJournal(bireyselodemedergiismi.getText());
				if(tempJournal!=null) {
					for(Subscription subscription:tempJournal.getSubscriptions()) {
						if(subscription.getSubscriber().getName().equals(bireyselodemeisim.getText()) && subscription.getSubscriber().getControlInfo()==Integer.parseInt(bireyselodemeccv.getText())) {
							subscription.acceptPayment(Double.parseDouble(bireyselodememiktari.getText()));
							flag=1;
						}
					}
				}
				else {
					JOptionPane.showMessageDialog(btnNewButton, "Böyle bir dergi bulunmamaktadır.");
					flag=2;
				}
				if(flag==0) {
					JOptionPane.showMessageDialog(btnNewButton, "Böyle bir abonelik bulunmamaktadır.");
				}else if (flag==1){
					JOptionPane.showMessageDialog(btnNewButton, "Ödeme gerçekleşti.");
				}
			}
		});
		bireyselodemebutton.setBackground(Color.LIGHT_GRAY);
		bireyselodemebutton.setBounds(281, 534, 93, 69);
		panel_3.add(bireyselodemebutton);
		
		JTextArea txtrJournalNationalGeographic_1_1 = new JTextArea();
		txtrJournalNationalGeographic_1_1.setEditable(false);
		txtrJournalNationalGeographic_1_1.setText("National Geographic\t3548-6245\t210₺\r\nCosmopolitan\t\t6524-9837\t250₺\r\nVogue\t\t2538-6459\t200₺\r\nModern\t\t6589-4125\t190₺\r\nTime\t\t6354-8574\t220₺\r\n\r\n\r\n\r\n\r\n\r\n");
		txtrJournalNationalGeographic_1_1.setFont(new Font("Times New Roman", Font.PLAIN, 16));
		txtrJournalNationalGeographic_1_1.setBounds(352, 123, 341, 108);
		panel_3.add(txtrJournalNationalGeographic_1_1);
		
		JLabel lblNewLabel_2_2_1_1_1_3_1 = new JLabel("Dergi");
		lblNewLabel_2_2_1_1_1_3_1.setHorizontalAlignment(SwingConstants.LEFT);
		lblNewLabel_2_2_1_1_1_3_1.setFont(new Font("Times New Roman", Font.BOLD, 25));
		lblNewLabel_2_2_1_1_1_3_1.setBounds(351, 84, 64, 39);
		panel_3.add(lblNewLabel_2_2_1_1_1_3_1);
		
		JLabel lblNewLabel_2_2_1_1_1_1_1_1 = new JLabel("Issn");
		lblNewLabel_2_2_1_1_1_1_1_1.setHorizontalAlignment(SwingConstants.LEFT);
		lblNewLabel_2_2_1_1_1_1_1_1.setFont(new Font("Times New Roman", Font.BOLD, 25));
		lblNewLabel_2_2_1_1_1_1_1_1.setBounds(533, 84, 64, 39);
		panel_3.add(lblNewLabel_2_2_1_1_1_1_1_1);
		
		JLabel lblNewLabel_2_2_1_1_1_2_1_1 = new JLabel("Fiyat");
		lblNewLabel_2_2_1_1_1_2_1_1.setHorizontalAlignment(SwingConstants.LEFT);
		lblNewLabel_2_2_1_1_1_2_1_1.setFont(new Font("Times New Roman", Font.BOLD, 25));
		lblNewLabel_2_2_1_1_1_2_1_1.setBounds(619, 84, 64, 39);
		panel_3.add(lblNewLabel_2_2_1_1_1_2_1_1);
		
		JPanel panel_4 = new JPanel();
		panel_4.setBackground(new Color(255, 255, 255));
		w_tabpane.addTab("Son Abonelik Bilgi", null, panel_4, null);
		w_tabpane.setForegroundAt(4, new Color(255, 255, 255));
		w_tabpane.setBackgroundAt(4, new Color(0, 0, 0));
		panel_4.setLayout(null);
		
		JComboBox ogrenyil = new JComboBox(arr2);
		ogrenyil.setBounds(344, 509, 72, 39);
		panel_4.add(ogrenyil);
		
		JComboBox ogrenay = new JComboBox(arr);
		ogrenay.setBounds(270, 509, 72, 39);
		panel_4.add(ogrenay);
		
		JTextArea textArea = new JTextArea();
		textArea.setEditable(false);
		textArea.setBounds(10, 44, 673, 414);
		panel_4.add(textArea);
		
		JButton og = new JButton("Öğren");
		og.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				textArea.setText(null);
				Thread thread1 = new Thread() {
					@Override
					public void run() {
						int control = 0;
						for(Subscription subs:distributor.report(ogrenay.getSelectedIndex()+1, ogrenyil.getSelectedIndex()+2010)) {
							try {
								if(control==4) {
									textArea.setText(null);
									control=0;
								}
								textArea.append(subs.toString()+"\n");
								Thread.sleep(2000);
								control++;
								
							} catch (InterruptedException e) {
								e.printStackTrace();
							}
						}textArea.append((ogrenyil.getSelectedIndex()+2010)+" yılının " + (ogrenay.getSelectedIndex()+1) + ". ayında aboneliği bitecek müşteriler bu kadar.");
					}
				};	
				thread1.start();
			}
		});
		
		og.setBackground(Color.LIGHT_GRAY);
		og.setBounds(301, 558, 90, 57);
		panel_4.add(og);
		
		JLabel lblNewLabel_2_3_1_1_1 = new JLabel("Yıl");
		lblNewLabel_2_3_1_1_1.setHorizontalAlignment(SwingConstants.LEFT);
		lblNewLabel_2_3_1_1_1.setFont(new Font("Times New Roman", Font.PLAIN, 25));
		lblNewLabel_2_3_1_1_1.setBounds(344, 470, 72, 39);
		panel_4.add(lblNewLabel_2_3_1_1_1);

		JLabel lblNewLabel_2_3_1_3 = new JLabel("Ay");
		lblNewLabel_2_3_1_3.setHorizontalAlignment(SwingConstants.LEFT);
		lblNewLabel_2_3_1_3.setFont(new Font("Times New Roman", Font.PLAIN, 25));
		lblNewLabel_2_3_1_3.setBounds(270, 470, 72, 39);
		panel_4.add(lblNewLabel_2_3_1_3);
		
		JLabel lblSon = new JLabel("Son Abonelik Bilgi");
		lblSon.setForeground(Color.BLACK);
		lblSon.setFont(new Font("Times New Roman", Font.BOLD, 30));
		lblSon.setBounds(225, 0, 243, 39);
		panel_4.add(lblSon);
		
		JPanel panel_5 = new JPanel();
		panel_5.setBackground(new Color(255, 255, 255));
		w_tabpane.addTab("Ödeme Bilgi", null, panel_5, null);
		w_tabpane.setForegroundAt(5, new Color(255, 255, 255));
		w_tabpane.setBackgroundAt(5, new Color(0, 0, 0));
		panel_5.setLayout(null);
		
		JComboBox ogrenyil_1 = new JComboBox(arr2);
		ogrenyil_1.setBounds(425, 142, 108, 39);
		panel_5.add(ogrenyil_1);
		
		JTextArea textArea_1 = new JTextArea();
		textArea_1.setEditable(false);
		textArea_1.setFont(new Font("Times New Roman", Font.BOLD, 30));
		textArea_1.setBounds(10, 61, 390, 326);
		panel_5.add(textArea_1);
		
		JButton og_1 = new JButton("Öğren");
		og_1.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				double toplamOdeme = 0;
				for(Journal journal:distributor.journals.values()) {
					for(Subscription subscription:journal.getSubscriptions()) {
						if(subscription.getDates().getStartYear() == ogrenyil_1.getSelectedIndex()+2010) {//Aboneliklerin kayıt yılı ile istenilen yıl eşit ise aboneliğin ödemesini toplamOdeme ye ekliyorum.
							toplamOdeme+=subscription.getPayment().getReceivedPayment();
						}
					}
				}
				textArea_1.setText((ogrenyil_1.getSelectedIndex()+2010)+" Yılında\n"+"Toplam Ödeme: "+String.valueOf(toplamOdeme));
			}
		});
		
		og_1.setBackground(Color.LIGHT_GRAY);
		og_1.setBounds(543, 103, 99, 78);
		panel_5.add(og_1);
		
		JLabel lblNewLabel_2_3_1_1_1_1 = new JLabel("Yıl");
		lblNewLabel_2_3_1_1_1_1.setHorizontalAlignment(SwingConstants.LEFT);
		lblNewLabel_2_3_1_1_1_1.setFont(new Font("Times New Roman", Font.PLAIN, 25));
		lblNewLabel_2_3_1_1_1_1.setBounds(425, 103, 108, 39);
		panel_5.add(lblNewLabel_2_3_1_1_1_1);
		
		JLabel lblIstenilenYlIerisindeki = new JLabel("İstenilen Yıl İçerisindeki Ödemeler");
		lblIstenilenYlIerisindeki.setForeground(Color.BLACK);
		lblIstenilenYlIerisindeki.setFont(new Font("Times New Roman", Font.BOLD, 30));
		lblIstenilenYlIerisindeki.setBounds(111, 10, 460, 39);
		panel_5.add(lblIstenilenYlIerisindeki);
		
		
		JButton btnNewButton_2 = new JButton("Çıkış");
		btnNewButton_2.setBounds(761, 10, 164, 89);
		btnNewButton_2.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				distributor.saveState("Kayit.txt");
				JOptionPane.showMessageDialog(btnNewButton, "Başarıyla çıkış yaptınız.");
				dispose();
			}
		});
		btnNewButton_2.setForeground(new Color(255, 255, 255));
		btnNewButton_2.setBackground(new Color(0, 0, 0));
		btnNewButton_2.setFont(new Font("Times New Roman", Font.PLAIN, 17));
		contentPane.add(btnNewButton_2);
		
		JTextArea txtrJournalNationalGeographic_1_1_1 = new JTextArea();
		txtrJournalNationalGeographic_1_1_1.setBounds(761, 98, 164, 34);
		txtrJournalNationalGeographic_1_1_1.setEditable(false);
		txtrJournalNationalGeographic_1_1_1.setBackground(new Color(0, 0, 0));
		txtrJournalNationalGeographic_1_1_1.setForeground(new Color(255, 255, 255));
		txtrJournalNationalGeographic_1_1_1.setText("Verilerinizin işlenmesi için\r\nLütfen \"Çıkış\" butonuna basınız");
		txtrJournalNationalGeographic_1_1_1.setFont(new Font("Times New Roman", Font.PLAIN, 12));
		contentPane.add(txtrJournalNationalGeographic_1_1_1);
	}
}
