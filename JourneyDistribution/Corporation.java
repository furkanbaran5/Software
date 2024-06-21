package proje;

import proje.Subscriber;

public class Corporation extends Subscriber implements java.io.Serializable{
	private int bankCode;
	private String bankName;
	private int issueDay;
	private int issueMonth;
	private int issueYear;
	private int accountNumber;

	public Corporation(String name, String address, int bankCode, String bankName, int issueDay, int issueMonth,int issueYear, int accountNumber) {	
		super(name, address);
		this.bankCode = bankCode;
		this.bankName = bankName;
		this.issueDay = issueDay;
		this.issueMonth = issueMonth;
		this.issueYear = issueYear;
		this.accountNumber = accountNumber;
	}
	
	@Override
	public String getBillingInformation() {//Subscriber hakkında bilgi
		return "Corporation "+ "[Name=" + getName() + ", Address=" + getAddress()+ ", bankCode=" + bankCode + ", bankName=" + bankName + "\nIssueDay=" + issueDay
				+ ", issueMonth=" + issueMonth + ", issueYear=" + issueYear + ", accountNumber=" + accountNumber
				+ "]";
	}

	@Override
	public int getControlInfo() {return accountNumber;}//Kurumsal abonelikse Hesap numarası ile kontrol ediyorum.
	

}
