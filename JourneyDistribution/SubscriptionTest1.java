package proje;

import static org.junit.Assert.*;

import org.junit.Test;

public class SubscriptionTest1 {

    Individual ind = new Individual("Ikbal", "Bingol", "1212 5648 6424 2123", 11, 2033, 359);
    Journal jour = new Journal("Modern", "6589-4125", 1, 1);
    DateInfo date = new DateInfo(6, 5, 2023);
    Subscription subs = new Subscription(date, 1, jour, ind);
    
    
    @Test
    public void testAcceptPayment() {
        subs.acceptPayment(100);
        assertEquals(100, subs.getPayment().getReceivedPayment(), 0.01);
    }
    
    @Test
    public void testCanSend() {
        assertTrue(subs.canSend(6, 2023));
    }

}
