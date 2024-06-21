package proje;

import java.io.Serializable;

public class Individual extends Subscriber implements java.io.Serializable{
	private String creditCardNo;
	private int expireMonth;
	private int expireYear;
	private int CCV;

	public Individual(String name, String address, String creditCardNo, int expireMonth, int expireYear, int cCV) {
		super(name, address);
		this.creditCardNo = creditCardNo;
		this.expireMonth = expireMonth;
		this.expireYear = expireYear;
		CCV = cCV;
	}
	
	public int getCCV() {return CCV;}

	@Override
	public String getBillingInformation() {//Subscriber hakkında bilgi
		return "Individual"+ " [Name=" + getName() + ", Address=" + getAddress() +", creditCardNo=" + creditCardNo + ", expireMonth=" + expireMonth + ", expireYear="
				+ expireYear + ", CCV=" + CCV + "]";
	}

	@Override
	public int getControlInfo() {return CCV;}//Bireysel abonelikse CCV numarası ile kontrol ediyorum.

}
