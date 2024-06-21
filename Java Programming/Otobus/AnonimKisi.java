package Lab2;

import java.util.Scanner;

public class AnonimKisi extends Kisi{

	public AnonimKisi(String ad, int iD, double bakiye) {
		super(ad, iD, bakiye);
	}

	@Override
	public boolean odemeYap(int x) {
		if(getBakiye()>=(getBirimUcret()*x)) {
			setBakiye(getBakiye()-(getBirimUcret()*x));
			System.out.println("Ödenmesi gereken tutar="+(getBirimUcret()*x)+"\n"+"Ödeme gerçekleşti ");
			return true;
		}
		System.out.println("Ödeme gerçekleşmedi ");
		return false;
	}
	
	
	

}
