package proje;

import static org.junit.Assert.*;

import org.junit.Test;

public class PaymentInfoTest1 {

    private PaymentInfo paymentInfo= new PaymentInfo();

    @Test
    public void testIncreasePayment() {
        paymentInfo.increasePayment(50.0);
        assertEquals(50.0, paymentInfo.getReceivedPayment(), 0.001);
    }

    @Test
    public void testGetReceivedPayment() {
        assertEquals(0.0, paymentInfo.getReceivedPayment(), 0.001);
    }

    @Test
    public void testToString() {
        String expected = "PaymentInfo [discountRatio=0.0, receivedPayment=0.0]";
        assertEquals(expected, paymentInfo.toString());
    }

}
