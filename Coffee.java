package Package1;

public class Coffee {
	private String name;
	private double inventory;
	private double currentPrice;
	private double firstPrice;
	private double cost;
	private int quantitySold=0;
	private int flag=0;

	public Coffee(String name, double inventory, double currentPrice, double firstPrice, double cost) {
		this.name = name;
		this.inventory = inventory;
		this.currentPrice = currentPrice;
		this.firstPrice = firstPrice;
		this.cost = cost;
	}

	public double getCost() {
		return cost;
	}

	public double getFirstPrice() {
		return firstPrice;
	}

	public String getName() {
		return name;
	}

	public double getCurrentPrice() {
		return currentPrice;
	}

	public void setFirstPrice(double firstPrice) {
		this.firstPrice = firstPrice;
	}

	public double getInventory() {
		return inventory;
	}

	public void setInventory(double inventory) {
		this.inventory = inventory;
	}

	public int getQuantitySold() {
		return quantitySold;
	}

	public int getFlag() {
		return flag;
	}

	public void setFlag(int flag) {
		this.flag = flag;
	}

	public void setQuantitySold(int quantitySold) {
		this.quantitySold = quantitySold;
	}

	public void setCurrentPrice(double currentPrice) {
		this.currentPrice = currentPrice;
	}
	
	
}
