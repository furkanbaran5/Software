package proje;

import java.util.ArrayList;

public class Journal implements java.io.Serializable{
	private String name;
	private String issn;
	private int frequency;
	private double issuePrice;
	private ArrayList<Subscription> subscriptions= new ArrayList<Subscription>();//Abonelikler için bir arraylist oluşturdum
	
	public Journal(String name, String issn, int frequency, double issuePrice) {
		this.name = name;
		this.issn = issn;
		this.frequency = frequency;
		this.issuePrice = issuePrice;
	}

	//getter setter methodları.
	public String getIssn() {return issn;}
	public int getFrequency() {return frequency;}
	public void setIssn(String issn) {this.issn = issn;}
	public double getIssuePrice() {return issuePrice;}
	public String getName() {return name;}
	public ArrayList<Subscription> getSubscriptions() {return subscriptions;}
	
	
	public void addSubscription(Subscription subscription) {//Yeni abonelik olduğunda Arrayliste kaydetme methodu.
		subscriptions.add(subscription);
	}
}