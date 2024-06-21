package Lab2;

public class IndirimliKisi extends Kisi{
	private int kredi;
	public IndirimliKisi(String ad, int iD, double bakiye,int kredi) {
		super(ad, iD, bakiye);
		this.kredi=kredi;
	}
	public int getKredi() {
		return kredi;
	}
	public void setKredi(int kredi) {
		this.kredi = kredi;
	}
	
	@Override
	public boolean odemeYap(int x) {
		if(kredi>=(getBirimUcret()*x)) {
			kredi -=getBakiye()-(getBirimUcret()*x);
			System.out.println("Ödeme gerçekleşti ");
		}
		else if(getBakiye()>=(getBirimUcret()*x)) {
			setBakiye(getBakiye()-(getBirimUcret()*x));
			System.out.println("Ödeme gerçekleşti ");
			kredi+=x;
			return true;
		}
		System.out.println("Ödeme gerçekleşmedi");
		return false;
	}
	@Override
	public String toString() {
		
		return "IndirimliKisi [kredi=" + kredi + "]";
	}
	
	
	
}
