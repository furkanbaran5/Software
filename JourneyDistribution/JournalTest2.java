package proje;

import static org.junit.Assert.*;

import org.junit.Test;

public class JournalTest2 {

    private Journal jour2 = new Journal("National Geographic", "3548-6245", 3, 21);

    @Test
    public void testGetIssn() {
        assertEquals("3548-6245", jour2.getIssn());
    }

    @Test
    public void testGetFrequency() {
        assertEquals(3, jour2.getFrequency());
    }

    @Test
    public void testSetIssn() {
        jour2.setIssn("9876-5432");
        assertEquals("9876-5432", jour2.getIssn());
    }

    @Test
    public void testGetIssuePrice() {
        assertEquals(21.0, jour2.getIssuePrice(), 0.001);
    }

    @Test
    public void testGetName() {
        assertEquals("National Geographic", jour2.getName());
    }

    @Test
    public void testGetSubscriptions() {
        assertNotNull(jour2.getSubscriptions());
        assertEquals(0, jour2.getSubscriptions().size());
    }

    @Test
    public void testAddSubscription() {
        Subscription subscription = new Subscription(new DateInfo(), 4, jour2, new Individual("Ikbal", "Bingol", "1212 5648 6424 2123", 11, 2033, 359));
        jour2.addSubscription(subscription);
        assertEquals(1, jour2.getSubscriptions().size());
        assertEquals(subscription, jour2.getSubscriptions().get(0));
    }

}
