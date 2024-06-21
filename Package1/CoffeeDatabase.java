package Package1;

import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.time.LocalDate;
import java.util.Hashtable;

public class CoffeeDatabase extends Database {

	int monthValue = LocalDate.now().getMonthValue();
	int yearValue = LocalDate.now().getYear();
	String abc;
	
    public Hashtable<String,Coffee> getCoffees() throws SQLException {
        PreparedStatement preparedStatement = connection.prepareStatement("select isim, stok,anlikfiyat,ilkfiyat, maliyet from kahve");
        ResultSet resultSet = preparedStatement.executeQuery();
        Hashtable<String,Coffee> coffeeList = new Hashtable<String, Coffee>();
        while (resultSet.next()) {
            Coffee coffee = new Coffee(resultSet.getString("isim").trim(), resultSet.getInt("stok"),resultSet.getDouble("anlikfiyat"),resultSet.getDouble("ilkfiyat"), resultSet.getDouble("maliyet"));
            coffeeList.put(coffee.getName(), coffee);
        }
        preparedStatement.close();
        return coffeeList;
    }
    
    
    
    public Hashtable<String,Person> getStaffs() throws SQLException {
        PreparedStatement preparedStatement = connection.prepareStatement("select isim, maas, bonus, kullaniciadi, sifre from calisanlar");
        ResultSet resultSet = preparedStatement.executeQuery();
        Hashtable<String,Person> staffs = new Hashtable<String, Person>();
        while (resultSet.next()) {
        	Person staff = new Person(resultSet.getString("isim"), resultSet.getString("kullaniciadi").trim(),resultSet.getString("sifre").trim(),resultSet.getDouble("maas"), resultSet.getDouble("bonus"));
        	
        	staffs.put(staff.getUserName(), staff);
        }
        preparedStatement.close();
        return staffs;
    }
    
    
    
    public double[][] getIncomes() throws SQLException{
    	PreparedStatement preparedStatement = connection.prepareStatement("select sno, x,x2,x3,x4,x5,x6,x7,x8,x9,x10,x11,x12 from aylikgelir");
        ResultSet resultSet = preparedStatement.executeQuery();
        double[][] incomes = new double[8][12];
        while (resultSet.next()) {
        	incomes[resultSet.getInt("sno")-1][0]=resultSet.getInt("x");
        	incomes[resultSet.getInt("sno")-1][1]=resultSet.getInt("x2");
        	incomes[resultSet.getInt("sno")-1][2]=resultSet.getInt("x3");
        	incomes[resultSet.getInt("sno")-1][3]=resultSet.getInt("x4");
        	incomes[resultSet.getInt("sno")-1][4]=resultSet.getInt("x5");
        	incomes[resultSet.getInt("sno")-1][5]=resultSet.getInt("x6");
        	incomes[resultSet.getInt("sno")-1][6]=resultSet.getInt("x7");
        	incomes[resultSet.getInt("sno")-1][7]=resultSet.getInt("x8");
        	incomes[resultSet.getInt("sno")-1][8]=resultSet.getInt("x9");
        	incomes[resultSet.getInt("sno")-1][9]=resultSet.getInt("x10");
        	incomes[resultSet.getInt("sno")-1][10]=resultSet.getInt("x11");
        	incomes[resultSet.getInt("sno")-1][11]=resultSet.getInt("x12");
        }
        preparedStatement.close();
        return incomes;
    }
    
    
    public double[][] getExpense() throws SQLException{
    	PreparedStatement preparedStatement = connection.prepareStatement("select sno, x,x2,x3,x4,x5,x6,x7,x8,x9,x10,x11,x12 from aylikgider");
        ResultSet resultSet = preparedStatement.executeQuery();
        double[][] expense = new double[8][12];
        while (resultSet.next()) {
        	expense[resultSet.getInt("sno")-1][0]=resultSet.getInt("x");
        	expense[resultSet.getInt("sno")-1][1]=resultSet.getInt("x2");
        	expense[resultSet.getInt("sno")-1][2]=resultSet.getInt("x3");
        	expense[resultSet.getInt("sno")-1][3]=resultSet.getInt("x4");
        	expense[resultSet.getInt("sno")-1][4]=resultSet.getInt("x5");
        	expense[resultSet.getInt("sno")-1][5]=resultSet.getInt("x6");
        	expense[resultSet.getInt("sno")-1][6]=resultSet.getInt("x7");
        	expense[resultSet.getInt("sno")-1][7]=resultSet.getInt("x8");
        	expense[resultSet.getInt("sno")-1][8]=resultSet.getInt("x9");
        	expense[resultSet.getInt("sno")-1][9]=resultSet.getInt("x10");
        	expense[resultSet.getInt("sno")-1][10]=resultSet.getInt("x11");
        	expense[resultSet.getInt("sno")-1][11]=resultSet.getInt("x12");
        }
        preparedStatement.close();
        return expense;
    }
    
    
    public void updateCoffees(Hashtable<String,Coffee> coffees) throws SQLException {//Borsa sistemi için
        PreparedStatement statement = connection.prepareStatement("update kahve set anlikfiyat=? where isim=?");
        coffees.forEach((String,Coffee) -> {
            try {
            	statement.setDouble(1, Coffee.getCurrentPrice());
                statement.setString(2, Coffee.getName());
				statement.addBatch();
			} catch (SQLException e) {
				e.printStackTrace();
			}
		});
        statement.executeBatch();
        statement.close();
    }
    
    public void updateInventory(Hashtable<String,Coffee> coffees) throws SQLException {//Stok işlemleri için
        PreparedStatement statement = connection.prepareStatement("update kahve set stok=? where isim=?");
        coffees.forEach((String,Coffee) -> {
            try {
            	statement.setDouble(1, Coffee.getInventory());
                statement.setString(2, Coffee.getName());
				statement.addBatch();
			} catch (SQLException e) {
				e.printStackTrace();
			}
		});
        statement.executeBatch();
        statement.close();
    }
    
    public void updateStaffs(Hashtable<String,Person> staffs) throws SQLException {//Tüm çalışanların bilgisi güncellenecek -> yönetici ekranı için
        PreparedStatement statement = connection.prepareStatement("update calisanlar set bonus=? where isim=?");
        staffs.forEach((String,Person) -> {
            try {
            	statement.setDouble(1, Person.getBonus());
                statement.setString(2, Person.getName());
				statement.addBatch();
			} catch (SQLException e) {
				e.printStackTrace();
			}
		});
        statement.executeBatch();
        statement.close();
    }
    
    public void updateStaff(Person staff) throws SQLException {//Sadece 1 çalışanın bilgisi güncellenecek ->Çalışan ekranı için
        PreparedStatement statement = connection.prepareStatement("update calisanlar set bonus=? where isim=?");
        statement.setDouble(1, staff.getBonus());
        statement.setString(2, staff.getName());
        statement.addBatch();
        
        statement.executeBatch();
        statement.close();
    }
  
    public void updateIncomes(double[][] incomes) throws SQLException {//Güncel ayın gelirini güncelleme
    	switch (monthValue) {
	        case 1:
	        	abc ="x";
	        	break;
	        case 2:
	        	abc ="x2";
	            break;
	        case 3:
	        	abc ="x3";
	            break;
	        case 4:
	        	abc ="x4";
	            break;
	        case 5:
	        	abc ="x5";
	            break;
	        case 6:
	        	abc ="x6";
	            break;
	        case 7:
	        	abc ="x7";
	            break;
	        case 8:
	        	abc ="x8";
	            break;
	        case 9:
	        	abc ="x9";
	            break;
	        case 10:
	        	abc ="x10";
	            break;
	        case 11:
	        	abc ="x11";
	            break;
	        case 12:
	        	abc ="x12";
	            break;
	    }
    	PreparedStatement statement = connection.prepareStatement("update aylikgelir set "+abc+"=? where sno=?");
        statement.setDouble(1, incomes[yearValue-2022][monthValue-1]);
        statement.setInt(2, yearValue-2021);
        statement.addBatch();
        
        statement.executeBatch();
        statement.close();
    }
    
    public void updateExpense(double[][] expense) throws SQLException {//Güncel ayın giderini güncelleme
    	switch (monthValue) {
	        case 1:
	        	abc ="x";
	        	break;
	        case 2:
	        	abc ="x2";
	            break;
	        case 3:
	        	abc ="x3";
	            break;
	        case 4:
	        	abc ="x4";
	            break;
	        case 5:
	        	abc ="x5";
	            break;
	        case 6:
	        	abc ="x6";
	            break;
	        case 7:
	        	abc ="x7";
	            break;
	        case 8:
	        	abc ="x8";
	            break;
	        case 9:
	        	abc ="x9";
	            break;
	        case 10:
	        	abc ="x10";
	            break;
	        case 11:
	        	abc ="x11";
	            break;
	        case 12:
	        	abc ="x12";
	            break;
	    }
    	PreparedStatement statement = connection.prepareStatement("update aylikgider set "+abc+"=? where sno=?");
        statement.setDouble(1, expense[yearValue-2022][monthValue-1]);
        statement.setInt(2, yearValue-2021);
        System.out.println( expense[yearValue-2022][monthValue-1]);
        statement.addBatch();
        
        statement.executeBatch();
        statement.close();
    }
}