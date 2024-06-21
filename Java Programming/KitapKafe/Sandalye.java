package Lab2_a;

public class Sandalye {
	private int no;
	private boolean doluluk=false;
	private final int ucret=15;
	public Sandalye(int no) {
		this.no = no;
	}
	public Sandalye() {
		// TODO Auto-generated constructor stub
	}
	public int getNo() {
		return no;
	}
	public int getUcret() {
		return ucret;
	}
	public void setDoluluk(boolean doluluk) {
		this.doluluk = doluluk;
	}
	@Override
	public String toString() {
		return "Sandalye [no=" + no + ", doluluk=" + doluluk + ", ucret=" + ucret + "]";
	}
	
	public boolean isDoluluk() {
		return doluluk;
	}
}
