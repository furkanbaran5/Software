package Lab2;

public abstract class Kisi {
	private String ad;
	private int ID;
	private double bakiye;
	private final int birimUcret=2;
	
	public Kisi(String ad, int iD, double bakiye) {
		this.ad = ad;
		this.ID = iD;
		this.bakiye = bakiye;
	}

	public double getBakiye() {
		return bakiye;
	}

	public void setBakiye(double bakiye) {
		this.bakiye = bakiye;
	}

	public int getBirimUcret() {
		return birimUcret;
	}

	
	
	@Override
	public String toString() {
		return "Kisi [ad=" + ad + ", ID=" + ID + ", bakiye=" + bakiye +  "]";
	}

	public abstract boolean odemeYap(int x) ;
}
