package Firkan;

import java.util.Arrays;

public class Basket {
	private int ID;
	private Item[] items = new Item[2];
	private MarketCard card;
	private int itemslength=0;
	private double totalPrice=0;
	
	public Basket(int iD) {
		this.ID = iD;
	}

	public void setCard(MarketCard card) {
		this.card = card;
	}
	
	public void addItem(Item item) {
		int i=0,flag=1;
		while(i<items.length && flag==1) {
			if(items[i]==null) {
				items[i]=item;
				flag=0;
				itemslength++;
				totalPrice+=items[i].getPrice();
			}
			i++;
		}
		
		if(flag==1) {
			System.out.println("Dolu");
		}
		
	}
	
	public void basketInfo() {
		if(card!=null) {
			card.addPoints(totalPrice);
		}
		System.out.println("Basket ID:" + ID + "\tNumber of items:" + itemslength + "\tTotal price:" + totalPrice);
	}

	@Override
	public String toString() {
		return "Basket [ID=" + ID + ", items=" + Arrays.toString(items) + ", card=" + card + "]";
	}
	
	
}
