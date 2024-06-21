package Lab2_a;

public class NormalKisi extends Kisi{

	public NormalKisi(String ad, int id, double bakiye) {
		super(ad, id, bakiye);
	}

	public boolean odemeYap(double ucret) {
		if(bakiye>=ucret) {
			setBakiye(bakiye-ucret);
			System.out.println("Bakiyenizden düşüm gerçekleşti");
			return true;
		}
		System.out.println("Bakiye Yetersiz.");
		return false;
	}
}
