package proje;

import java.io.Serializable;

public class PaymentInfo implements java.io.Serializable{
	private final double discountRatio = 0;
	private double receivedPayment;
	
	
	
	public PaymentInfo() {
		receivedPayment=0;
	}

	@Override
	public String toString() {
		return "PaymentInfo [discountRatio=" + discountRatio + ", receivedPayment=" + receivedPayment + "]";
	}

	public void increasePayment(double amount) {
		receivedPayment+=amount;
	}

	public double getReceivedPayment() {
		return receivedPayment;
	}
}
