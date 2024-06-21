package proje;

import static org.junit.Assert.*;

import org.junit.Before;
import org.junit.Test;

public class DistributorTest1 {
    
	private Distributor distributor = new Distributor();

    @Test
    public void testAddJournal() {
        // Yeni bir dergi ekleniyor
        Journal jour = new Journal("National Geographic", "1234-5678", 1, 15);
        assertTrue(distributor.addJournal(jour));

        // Aynı dergi tekrar ekleniyor, false dönmeli
        assertFalse(distributor.addJournal(jour));
    }

    @Test
    public void testAddSubscriberAndSearchSubscriber() {
        // Yeni bir abone ekleniyor
        Individual ind = new Individual("Ahmet", "Istanbul", "1111 2222 3333 4444", 5, 2023, 123);
        
        // Abone ekleniyor true donmeli.
        assertTrue(distributor.addSubscriber(ind));
        
        // Aynı abone tekrar ekleniyor, false dönmeli
        assertFalse(distributor.addSubscriber(ind));
        
        // Eklediğimiz aboneyi bulma methodu,null dönerse yoktur onun dışında vardır.
       assertNotNull(distributor.searchSubscriber("Ahmet"));
    }

    @Test
    public void testAddSubscription() {
        // Yeni bir abonelik ekleniyor
        Journal jour = new Journal("National Geographic", "1234-5678", 1, 15);
        DateInfo date = new DateInfo(5, 4, 2023);
        Individual ind = new Individual("John Doe", "123 Main St", "1111 2222 3333 4444", 5, 2023, 123);
        Subscription subs = new Subscription(date, 1, jour, ind);
        distributor.addJournal(jour);
        for(Journal journal:distributor.journals.values()) {
        	if(journal.equals(jour)) {
        		journal.addSubscription(subs);
        	}
        }
        

        // Aynı abone ve dergi için tekrar ekleniyor, true dönmeli ve kopya sayısı 2 olmalı
        assertTrue(distributor.addSubscription("National Geographic", ind, subs));
        assertEquals(2, subs.getCopies());
    }

    @Test
    public void testListAllSendingOrders() {
        // Örnek dergi, abone , abonelik ve istenen tarih
        Journal jour = new Journal("National Geographic", "1234-5678", 1, 15);
        DateInfo date = new DateInfo(5, 4, 2023);
        Individual ind = new Individual("John Doe", "123 Main St", "1111 2222 3333 4444", 5, 2023, 123);
        Subscription subs = new Subscription(date, 1, jour, ind);
        int month = 5;
        int year = 2023;
        
        distributor.addJournal(jour);
        distributor.addSubscriber(ind);
        distributor.searchJournal("National Geographic").addSubscription(subs);

        // Metot çağrılıyor ve sonuç terminalden kontrol ediliyor.
        distributor.listAllSendingOrders(month, year);
    }

}
