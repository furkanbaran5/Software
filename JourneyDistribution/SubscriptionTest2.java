package proje;

import static org.junit.Assert.*;

import org.junit.Test;

public class SubscriptionTest2 {

	Individual ind = new Individual("Erdem", "Rize", "5353 5648 6424 2123", 10, 2032, 358);
    Journal jour = new Journal("Cosmopolitan", "6524-9837", 2, 25);
    DateInfo date = new DateInfo(6, 5, 2023);
    Subscription subs = new Subscription(date, 1, jour, ind);
    
    
    @Test
    public void testAcceptPayment() {
        subs.acceptPayment(250);
        assertEquals(250, subs.getPayment().getReceivedPayment(), 0.01);
    }
    
    @Test
    public void testCanSend() {
        assertTrue(subs.canSend(6, 2023));
    }

}
