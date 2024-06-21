package proje;

import java.io.File;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.ObjectInputStream;
import java.io.ObjectOutputStream;
import java.io.Serializable;
import java.util.ArrayList;
import java.util.Enumeration;
import java.util.Hashtable;
import java.util.List;
import java.util.Scanner;
import java.util.Vector;


public class Distributor implements java.io.Serializable{
	public Hashtable<String, Journal> journals = new Hashtable<String, Journal>();
	public Vector<Subscriber> subscribers = new Vector<Subscriber>();
	
	//Gönderilen dergiyi journals hashtable'ına ekliyorum.
	public boolean addJournal(Journal journal) {
		if(journals.put(journal.getIssn(), journal) == null) {
			return true;
		}
		return false;
	}
	
	//Journals hashtable'ında gezip aranılan dergiyi buluyorum. UML de Issn numarasına göre aranması istemişti ama 
	//yeni abone eklemek istediğim zaman dergiyi ismiyle aramanın ISSN numarasına göre aramaktan daha mantıklı geldiği 
	//için isimle değiştirdim.
	public Journal searchJournal(String journalName) {
		for(Journal journal:journals.values()) {			
			if(journal.getName().equals(journalName)) {
				return journal;
			}
		}
		return null;
	}
	
	//Gonderilen aboneyi Subscribers vectörüne ekliyorum.
	public boolean addSubscriber(Subscriber subscriber) {
		for(Subscriber subs: subscribers) {
			if(subs.getBillingInformation().equals(subscriber.getBillingInformation())) {
				return false;
			}
		}
		subscribers.add(subscriber);
		return true;
	}
	
	//Subscribers vectörünü gezip aranılan Subscriber'ı ismiyle arayıp buluyorum.
	public Subscriber searchSubscriber(String subscriberName) {
		for(Subscriber subs:subscribers) {
			if(subs.getName().equals(subscriberName)) {
				return subs;
			}
		}
		return null;
	}
	
	//Gönderilen dergi ismini aratıp abonelik arraylistini çağırıp her bir aboneliğini geziyorum.
	public boolean addSubscription(String journalName,Subscriber subscriber,Subscription subscription) {
		for(Subscription subs:searchJournal(journalName).getSubscriptions()) {
			if(subs.getSubscriber().getBillingInformation().equals(subscriber.getBillingInformation())) {//Gönderilen Subscriber ile aboneliğin Subscriber'ının getBillingInformation methodu eşitse kopyayı 1 arttırıyorum.
				subs.setCopies(subs.getCopies()+1);
				return true;
			}
		}
		return false;
	}
	
	//Journals dizindeki dergileri gezip her birinin aboneliğini geziyorum. Aboneliğin canSend(Gönderdiğim ay ve yıl değerine 
	//göre hesap yapıp gereken ödemeyi yapmış mı diye kontrol eden method) methoduna Ay ve Yılı gönderiyorum ödeme yapılmışsa
	//dergiyi alabileceğini belli etmek için terminale çıktı veriyorum.
	public void listAllSendingOrders(int month,int year) {
		for(Journal journal:journals.values()) {
			System.out.println("Journal: "+ journal.getName());
			for(Subscription subs:journal.getSubscriptions()){
				if(subs.canSend(month, year)==true) {
					System.out.println("\t"+subs.getSubscriber().getBillingInformation());
				}
			}
		}   
	}
	
	//İstenilen derginin ismini alıp istenilen ayda ödeme yapmış mı diye üstteki methoddaki gibi canSend methodunu kullanıyorum
	//ve ödemişse terminale yazdırıyorum.
	public void listSendingOrders(String journalName,int month,int year) {
		System.out.println("Journal: " +searchJournal(journalName).getName());
		for(Subscription subs:searchJournal(journalName).getSubscriptions()){
			if(subs.canSend(month, year)==true) {
				System.out.println("\t"+subs.getSubscriber().getBillingInformation());
			}
		}
	}
	
	//1 yıllık ödemesini yapmamış abonelikleri listeliyorum 
	public void listIncompletePayments() {
		for(Journal journal:journals.values()) {//Dergileri arıyorum
			System.out.println("Journal: "+ journal.getName());
			for(Subscription subscription:journal.getSubscriptions()){//dergilerin abonelerini arıyorum
				double odenmesiGerekenTutar=journal.getFrequency()*journal.getIssuePrice()*subscription.getCopies()*12;//Sıklık*ücret*kopya sayısı* 12ay
				
				if(odenmesiGerekenTutar > subscription.getPayment().getReceivedPayment()) {//ödemeyenleri çıktı olarak veriyorum
					System.out.println("\tSubscriber: "+subscription.getSubscriber().getName() + "\n\t\tÖdediği tutar: "+ subscription.getPayment().getReceivedPayment() +"\n\t\tKalan tutar: "
				+ (odenmesiGerekenTutar - subscription.getPayment().getReceivedPayment()) );
				}
				
			}
		} 
	}
	
	//Subscriber ismine göre aboneliği arıyorum
	public void listSubscriptions1(String subscriberName) {
		for(Journal journal:journals.values()) {
			for(Subscription subs:journal.getSubscriptions()){
				if(subs.getSubscriber().getName().equals(subscriberName)) {
					System.out.println(subs+" \n\tJournal: " + journal.getName() );
				}
			}
		} 
	}
	
	
	//Dergi ismine göre abonelikleri listeliyorum
	public void listSubscriptions2(String journalName) {
		System.out.println("Journal: " +searchJournal(journalName).getName());
		for(Subscription subs:searchJournal(journalName).getSubscriptions()){
			System.out.println("\t"+subs.getSubscriber().getBillingInformation());
		}
	}
	
	//Dosyadan önce journals'ı sonra da subscribers'ı okuyorum.
	public void loadState(String fileName)throws ClassNotFoundException {
		try(ObjectInputStream in = new ObjectInputStream(new FileInputStream(fileName))) {
				journals = (Hashtable<String, Journal>) in.readObject();
				subscribers.addAll((Vector<Subscriber>) in.readObject());
				in.close();
			}
		catch(IOException e) {
			e.printStackTrace();
		}
	}
	
	//Dosyaya önce journals'ı sonra da subscribers'ı yazıyorum
	public void saveState(String fileName) {
		try (ObjectOutputStream out = new ObjectOutputStream(new FileOutputStream(fileName))) {
			out.writeObject(journals);
	        out.writeObject(subscribers);
	        out.close();
	    } catch (IOException e) {
	        e.printStackTrace();
	    }
	}
	
	//İstenilen tarihte bitecek olan abonelikleri listelemek için abonelikleri arrayliste ekleyip, Gui'den thread ile ekrana yazmak üzere return ediyorum.
	public ArrayList<Subscription> report(int ay, int yil) {
		ArrayList<Subscription> subscriptions = new ArrayList<Subscription>();
		for(Journal journal:journals.values()) {//Dergileri geziyorum
			for(Subscription subs:journal.getSubscriptions()) {//Abonelikleri geziyorum
				if(subs.getDates().getStartYear()+1 == yil && subs.getDates().getEndMonth()<12) {//Kayıt yılının 1 fazlası ile istenilen yıl eşit mi ve bitiş ayı aralıktan önce mi diye kontrol ediyorum
					if(subs.getDates().getEndMonth() == ay) {//Bitiş ayı ile istenilen ay eşit ise Guide ekrana yazdırmak için geçici arrayliste ekliyorum.
						subscriptions.add(subs);
					}
				}else if(subs.getDates().getStartYear() == yil && subs.getDates().getEndMonth()==12) {//aboneliği ocak ayında başlamış abone mi.
					subscriptions.add(subs);
				}
			}
		}
		return subscriptions;
	}
}
