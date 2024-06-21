package proje;

import static org.junit.Assert.*;

import org.junit.Test;

public class PaymentInfoTest2 {

    private PaymentInfo paymentInfo = new PaymentInfo();;

    @Test
    public void testIncreasePayment() {
        paymentInfo.increasePayment(100.0);
        assertEquals(100.0, paymentInfo.getReceivedPayment(), 0.001);
    }

    @Test
    public void testMultipleIncreasePayment() {
        paymentInfo.increasePayment(50.0);
        paymentInfo.increasePayment(30.0);
        paymentInfo.increasePayment(20.0);
        assertEquals(100.0, paymentInfo.getReceivedPayment(), 0.001);
    }

    @Test
    public void testGetReceivedPaymentWithDiscount() {
        PaymentInfo discountedPaymentInfo = new PaymentInfo();
        discountedPaymentInfo.increasePayment(200.0);
        assertEquals(200.0, discountedPaymentInfo.getReceivedPayment(), 0.001);
    }

    @Test
    public void testToString() {
        String expected = "PaymentInfo [discountRatio=0.0, receivedPayment=0.0]";
        assertEquals(expected, paymentInfo.toString());
    }

}
