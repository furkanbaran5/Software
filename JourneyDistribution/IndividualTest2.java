package proje;

import static org.junit.Assert.*;

import org.junit.Test;

public class IndividualTest2 {

    private Individual individual = new Individual("Omer", "Hatay", "3131 5648 6424 2123", 8, 2030, 356);;

    @Test
    public void testGetCCV() {
        assertEquals(356, individual.getCCV());
    }

    @Test
    public void testGetBillingInformation() {
        String expected = "Individual [Name=Omer, Address=Hatay, creditCardNo=3131 5648 6424 2123, expireMonth=8, expireYear=2030, CCV=356]";
        assertEquals(expected, individual.getBillingInformation());
    }

    @Test
    public void testGetControlInfo() {
        assertEquals(356, individual.getControlInfo());
    }
}
