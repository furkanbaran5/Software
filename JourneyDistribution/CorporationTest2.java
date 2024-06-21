package proje;

import static org.junit.Assert.*;

import org.junit.Before;
import org.junit.Test;

public class CorporationTest2 {

    Corporation corporation = new Corporation("Fanuk", "Bursa", 16, "VakifBank", 5, 11, 2024, 336);

    @Test
    public void testGetBillingInformation() {
    	String expected = "Corporation [Name=Fanuk, Address=Bursa, bankCode=16, bankName=VakifBank\nIssueDay=5, issueMonth=11, issueYear=2024, accountNumber=336]";
        assertEquals(expected, corporation.getBillingInformation());
    }

    @Test
    public void testGetControlInfo() {
    	int expected = 336;
        assertEquals(expected, corporation.getControlInfo());
    }
}

