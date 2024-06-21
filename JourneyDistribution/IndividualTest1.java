package proje;

import static org.junit.Assert.*;

import org.junit.Test;

public class IndividualTest1 {

	 private Individual individual = new Individual("Furkan", "Diyarbakir", "2121 5648 6424 2123", 9, 2031, 357);;

	 @Test
	 public void testGetCCV() {
		 assertEquals(357, individual.getCCV());
	 }

	 @Test	    
	 public void testGetBillingInformation() {	        
		 String expected = "Individual [Name=Furkan, Address=Diyarbakir, creditCardNo=2121 5648 6424 2123, expireMonth=9, expireYear=2031, CCV=357]";	     
		 assertEquals(expected, individual.getBillingInformation());	    
	 } 
	 @Test
	 public void testGetControlInfo() {
		 assertEquals(357, individual.getControlInfo());
	 }
}
