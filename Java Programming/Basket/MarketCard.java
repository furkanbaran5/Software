package Firkan;

public class MarketCard {
	private int cardNo;
	private double points=0;
	public MarketCard(int cardNo) {
		this.cardNo = cardNo;
	}
	public double getPoints() {
		return points;
	}
	public void addPoints(double fee) {
		points+=(fee/10);
	}
}
