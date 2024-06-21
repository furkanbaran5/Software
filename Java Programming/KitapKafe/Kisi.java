package Lab2_a;

public abstract class Kisi {
	protected String ad;
	protected int id;
	protected double bakiye;
	public Kisi(String ad, int id, double bakiye) {
		this.ad = ad;
		this.id = id;
		this.bakiye = bakiye;
	}
	public void setBakiye(double bakiye) {
		this.bakiye = bakiye;
	}
	
	@Override
	public String toString() {
		return "Kisi [ad=" + ad + ", id=" + id + ", bakiye=" + bakiye + "]" ;
	}
	public abstract boolean odemeYap(double bakiye);
	
}
