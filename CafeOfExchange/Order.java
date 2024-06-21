package Package1;

import java.util.Hashtable;

public class Order {
        
	public void order(String name,Hashtable<String,Coffee> coffees,Person staff, int number) {
		coffees.get(name).setInventory(coffees.get(name).getInventory()-number);//Envanterden number eksildi
		coffees.get(name).setQuantitySold(coffees.get(name).getQuantitySold()+number);//Satılanlara number tane eklendi
		staff.setBonus(staff.getBonus()+number);//Çalışanın bonusuna sattığı kahve adedi eklendi
	}
	
	public void sellingControl(Hashtable<String,Coffee> coffees) {
		coffees.forEach((String,coffee) -> {
			if(coffee.getFlag()==0) {//Zamlı değilse
				//10 kahve baremini geçen her kahve için %10 zam yap veya altta kalan her kahve için %10 indirim yap
				if(coffee.getQuantitySold()>11 || coffee.getQuantitySold()<6) {
					coffee.setCurrentPrice(coffee.getCurrentPrice() + coffee.getCurrentPrice() * (coffee.getQuantitySold()-10) / 20);
					coffee.setFlag(1);//Zamlı olarak güncelle
				}
				coffee.setQuantitySold(0);//satılmış bilgisini sıfırla
			}
			else {//Flag 1 ise zamlıdır
				coffee.setCurrentPrice(coffee.getFirstPrice());//fiyatı ilk fiyata çevir
				coffee.setQuantitySold(0);//satılmış bilgisini sıfırla
				coffee.setFlag(0);//Zamsız olarak güncelle
			}
		});
		
	}
	
	
}
