package Lab2_a;

public class Abonman extends Kisi{
	private int kredi;

	public Abonman(String ad, int id, double bakiye, int kredi) {
		super(ad, id, bakiye);
		this.kredi = kredi;
	}

	@Override
	public boolean odemeYap(double ucret) {
		
		if(kredi>=5) {
			kredi-=5;
			System.out.println("Giriş hakkından düşüm gerçekleşti");
			return true;
		}
		else if(bakiye>=ucret) {
			setBakiye(bakiye-ucret);
			System.out.println("Bakiyenizden düşüm gerçekleşti");
			kredi++;
			return true;
		}
		System.out.println("Bakiye Yetersiz.");
		return false;
	}

	public int getKredi() {
		return kredi;
	}

	public void setKredi(int kredi) {
		this.kredi = kredi;
	}

	@Override
	public String toString() {
		return "Kisi [ad=" + ad + ", id=" + id + ", bakiye=" + bakiye + "] Abonman [kredi=" + kredi + "]";
	}
	
	
}
