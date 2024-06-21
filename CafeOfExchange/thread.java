/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package Package1;

import java.sql.SQLException;
import java.util.Calendar;

/**
 *
 * @author ErdemKARACA
 */
public class thread extends Thread {
    
    @Override
    public void run() {
        while (true) {
            int currentSecond = Calendar.getInstance().get(Calendar.SECOND);
            if (currentSecond % 10 == 0) {
                System.out.println(currentSecond);
                EntranceScreen.order.sellingControl(EntranceScreen.coffees);
                try {
                	EntranceScreen.coffeeDatabase.updateCoffees(EntranceScreen.coffees);
					Thread.sleep(8000);
				} catch (InterruptedException e) {
					e.printStackTrace();
				} catch (SQLException e) {
					e.printStackTrace();
				}
            }
           
        }
    }
}
