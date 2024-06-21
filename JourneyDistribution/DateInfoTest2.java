package proje;

import static org.junit.Assert.*;

import org.junit.Test;

public class DateInfoTest2 {
	DateInfo date1 = new DateInfo(3, 2, 2025);
	
	@Test
	public void testToStringWithSpecificDate() {
		String expected = "DateInfo [startMonth=3, endMonth=2, startYear=2025]";
		assertEquals(expected, date1.toString());
	}

}
