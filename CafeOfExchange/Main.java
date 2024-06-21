package Package1;

import java.sql.SQLException;
import java.time.LocalDate;
import java.util.Date;
import java.util.Hashtable;

public class Main {

	public static void main(String[] args) throws SQLException {

		Management management = new Management();
		Order order = new Order();
          //      Management management = new Management(manager, muhasebe,  15000);
		
		Hashtable<String,Coffee> coffees = new Hashtable<String, Coffee>();
		
		Hashtable<String,Person> staffs = new Hashtable<String, Person>();
		
		staffs.put("ahmettt",new Person("Ahmet Yılmaz", "ahmettt", "ahmedovski", 17000, 0));
		staffs.put("celill",new Person("Celal Bal", "celill", "celo", 20000, 0));
		staffs.put("sevdebagar",new Person("Sevde Bagar", "sevdebagar", "sevdee", 18000, 0));
		staffs.put("halo",new Person("Halil Celil", "halo", "halodayi", 21000, 0));
		
		
		coffees.put("Espresso", new Coffee("Espresso", 100, 25, 25, 10));
		coffees.put("Latte", new Coffee("Latte", 101, 22, 30, 10));
		coffees.put("Capuccino", new Coffee("Capuccino", 112, 30, 20, 10));
		coffees.put("Caramel", new Coffee("Caramel", 125, 50, 30, 10));
		
		//Veritabanına Erişim
		CoffeeDatabase coffeeDatabase = new CoffeeDatabase();
		//Kahve ve çalışan bilgilerini alttaki hashlere ata
		/*Hashtable<String,Coffee> coffees = coffeeDatabase.getCoffees();
		Hashtable<String,Person> staffs = coffeeDatabase.getStaffs();

		staffs.forEach((String,Person) -> {
            System.out.println(Person.getUserName());
            Person.setBonus(100);
		});
		Person x = new Person(null, "fatmatez", null, 0, 0);
		System.out.println(staffs.get("fatmatez").getName());
		
		//Çalışanların bonusunu güncelle
		staffs.get("mehmetak").setBonus(20);
		coffeeDatabase.updateStaff(staffs.get("mehmetak"));
		
		//Kahveyi güncelle
		coffeeDatabase.updateCoffees(coffees);*/
		
		double[][] expense = new double[8][12];
		expense = coffeeDatabase.getExpense();
		for(int i=0;i<8;i++) {
        	for(int j=0;j<12;j++) {
        		System.out.print(expense[i][j] + "  ");
        	}
        	System.out.println();
        }
		//management.paySalary(staffs, expense);
        for(int i=0;i<8;i++) {
        	for(int j=0;j<12;j++) {
        		System.out.print(expense[i][j] + "  ");
        	}
        	System.out.println();
        }
       
        coffeeDatabase.updateExpense(expense);
	}

}
