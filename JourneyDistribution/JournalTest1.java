package proje;

import static org.junit.Assert.*;

import org.junit.Test;


public class JournalTest1 {

    private Journal jour1 = new Journal("Vogue", "2538-6459", 3, 20);

    @Test
    public void testGetIssn() {
        assertEquals("2538-6459", jour1.getIssn());
    }

    @Test
    public void testGetFrequency() {
        assertEquals(3, jour1.getFrequency());
    }

    @Test
    public void testSetIssn() {
        jour1.setIssn("1234-5678");
        assertEquals("1234-5678", jour1.getIssn());
    }

    @Test
    public void testGetIssuePrice() {
        assertEquals(20.0, jour1.getIssuePrice(), 0.001);
    }

    @Test
    public void testGetName() {
        assertEquals("Vogue", jour1.getName());
    }

    @Test
    public void testGetSubscriptions() {
        assertNotNull(jour1.getSubscriptions());
        assertEquals(0, jour1.getSubscriptions().size());
    }

    @Test
    public void testAddSubscription() {
        Subscription subscription = new Subscription(new DateInfo(), 1, jour1, new Individual("Alperen", "Yalova", "7777 5648 6424 2123", 12, 2034, 360));
        jour1.addSubscription(subscription);
        assertEquals(1, jour1.getSubscriptions().size());
        assertEquals(subscription, jour1.getSubscriptions().get(0));
    }

}
