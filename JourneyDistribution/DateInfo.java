package proje;

import java.io.Serializable;
import java.time.LocalDate;
import java.util.Date;

public class DateInfo implements java.io.Serializable{
	private int startMonth;
	private int endMonth;
	private int startYear;
	
	
	public DateInfo() {//Yeni aboneler için bu constructer'ı çağırıyorum güncel tarih alması için
		if(LocalDate.now().getMonthValue()==1) {//ocak ayında kayıt yapmışsa bitiş ayına aralık yapıyorum aksi halde bir önceki ay.
			startMonth = LocalDate.now().getMonthValue();
			endMonth = 12;
			startYear = LocalDate.now().getYear();
		}else {
			startMonth = LocalDate.now().getMonthValue();
			endMonth = LocalDate.now().getMonthValue()-1;
			startYear = LocalDate.now().getYear() ;
		}
	}
	public DateInfo(int startMonth, int endMonth, int startYear) {//Method ile çağırdığımda önceden kayıtlı aboneler için zaman üretiyorum.
		this.startMonth = startMonth;
		this.endMonth = endMonth;
		this.startYear = startYear;
	}
	
	@Override
	public String toString() {
		return "DateInfo [startMonth=" + startMonth + ", endMonth=" + endMonth + ", startYear=" + startYear + "]";
	}
	
	//Getter methodları
	public int getStartMonth() {return startMonth;}
	public int getStartYear() {return startYear;}
	public int getEndMonth() {return endMonth;}
}
