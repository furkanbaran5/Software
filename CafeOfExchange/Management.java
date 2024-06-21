package Package1;

import java.time.LocalDate;
import java.util.Hashtable;

public class Management {
	int monthValue = LocalDate.now().getMonthValue();
    int yearValue = LocalDate.now().getYear();
    private int rent=30000;//Kira değişebilir
    
    public void paySalary(Hashtable<String, Person> staffs,double[][] expense) {
        double allSalary = 0;
        for (Person staff : staffs.values()) {
            allSalary += staff.getSalary() + (0.5 * staff.getBonus());
            staff.setBonus(0);
        }
        expense[yearValue-2022][monthValue-1] += allSalary;
    }
	
    public void payRent(double[][] expense) {
    	expense[yearValue-2022][monthValue-1] += rent;
    }
	
    public void payTax(double[][] expense,double[][] incomes){
    	expense[yearValue-2022][monthValue-1] += (incomes[yearValue-2022][monthValue-1] * 0.18);
    }
	
    public void addInventory(Hashtable<String,Coffee> coffees , String name , double claim, double[][] expense) {
        double cost = claim * coffees.get(name).getCost();
        expense[yearValue-2022][monthValue-1] += cost;  
        coffees.get(name).setInventory(coffees.get(name).getInventory() + claim);
    }    
}
