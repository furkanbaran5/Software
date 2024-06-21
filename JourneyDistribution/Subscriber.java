package proje;

import java.io.Serializable;

public abstract class Subscriber implements java.io.Serializable{
	private String name;
	private String address;
	
	public Subscriber(String name, String address) {
		this.name = name;
		this.address = address;
	}

	//Getter ve setter methodları.
	public String getName() {return name;}
	public void setName(String name) {this.name = name;}
	public String getAddress() {return address;}
	public void setAddress(String address) {this.address = address;}

	
	public abstract String getBillingInformation();
	public abstract int getControlInfo();//Bu method ile Gui ekranında ödeme yaptığımda kim adına ödeme yapıldığını kontrol ediyorum.
}
