package proje;

import static org.junit.Assert.*;

import org.junit.Test;

public class DateInfoTest1 {
	DateInfo date2 = new DateInfo(4, 3, 2023);
	
	@Test
    public void testToStringWithDifferentSpecificDate() {
        String expected = "DateInfo [startMonth=4, endMonth=3, startYear=2023]";
        assertEquals(expected, date2.toString());
    }
}
