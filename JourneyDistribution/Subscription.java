package proje;

import java.io.Serializable;

public class Subscription implements java.io.Serializable{
	private final DateInfo dates;
	private PaymentInfo payment;
	private int copies;
	private final Journal journal;
	private final Subscriber subscriber;
	
	public Subscription(DateInfo dates, int copies, Journal journal, Subscriber subscriber) {
		this.dates = dates;
		this.journal = journal;
		this.copies = copies;
		this.subscriber = subscriber;
		payment = new PaymentInfo();
	}
	
	//Getter setter methodları.
	public Journal getJournal() {return journal;}
	public Subscriber getSubscriber() {return subscriber;}
	public int getCopies() {return copies;}
	public void setCopies(int copies) {this.copies = copies;}
	public PaymentInfo getPayment() {return payment;}
	public DateInfo getDates() {return dates;}


	public void acceptPayment(double amount) {
		payment.increasePayment(amount);
	}
	
	public boolean canSend(int issueMonth,int issueYear) {//İstenilen ayda ödeme yapılmış mı diye kontrol.
		if(dates.getStartYear()==issueYear) {//Yıllar eşit ise aylar kontrol edilecek
			if(issueMonth>=dates.getStartMonth()) {//İstenilen ay abonelik başlangıcından büyük ise ücreti hesaplar. İstenilen ay başlangıç ayından küçükse daha aboneliği yoktur.
				if((issueMonth-dates.getStartMonth())*(journal.getIssuePrice()*copies*journal.getFrequency())<=payment.getReceivedPayment()) {//Ay sayısı * dergi ücreti * copies * frequency <ödeme miktarı.
					return true;
				}
			}
		}else if(dates.getStartYear()+1==issueYear && dates.getEndMonth()>12) {//İstenilen yılın  abonelik başlangıcından bir yıl fazla ise(Bitiş ayı aralık ise aynı yıl içinde kayıt yapmıştır.). İstenilen yıl başlangıç yılı veya bir fazlasına eşit değilse aboneliği yoktur
			if(issueMonth<=dates.getEndMonth()) {//İstenilen ay abonelik bitişinden küçük ise hesaplama yapar. İstenilen ay başlangıç ayından büyükse daha aboneliği bitmiştir.
				if((issueMonth-dates.getStartMonth()+12)*(journal.getIssuePrice()*copies*journal.getFrequency())<=payment.getReceivedPayment()) {//Ay sayısı * dergi ücreti* copies * frequency <ödeme miktarı.
					return true;
				}
			}
		}
		return false;
	}

	@Override
	public String toString() {
		return "SUBSCRIPTION \n" + dates + "\n" + payment + "\nHangi dergiye kaç kopyası var= " + journal.getName() + " "+ copies + "\n" + subscriber.getBillingInformation() + "\n";
	}
}
