package proje;

import static org.junit.Assert.*;

import org.junit.Test;

import static org.junit.Assert.assertEquals;
import org.junit.Before;
import org.junit.Test;

public class CorporationTest {

    Corporation corporation = new Corporation("Koc", "Istanbul", 34, "Akbank", 6, 12, 2024, 335);

    @Test
    public void testGetBillingInformation() {
    	String expected = "Corporation [Name=Koc, Address=Istanbul, bankCode=34, bankName=Akbank\nIssueDay=6, issueMonth=12, issueYear=2024, accountNumber=335]";
        assertEquals(expected, corporation.getBillingInformation());
    }

    @Test
    public void testGetControlInfo() {
    	int expected = 335;
        assertEquals(expected, corporation.getControlInfo());
    }
}
