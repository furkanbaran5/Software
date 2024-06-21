package Package1;

public class Person {
	private String name;
	private String userName;
	private String password;
	private double salary;
	private double bonus;
	
	public Person(String name, String userName, String password, double salary, double bonus) {
		this.name = name;
		this.userName = userName;
		this.password = password;
		this.salary = salary;
		this.bonus = bonus;
	}

	public void setSalary(double salary) {
		this.salary = salary;
	}

	public double getSalary() {
		return salary;
	}

	public String getPassword() {
		return password;
	}
	
	public double getBonus() {
		return bonus;
	}

	public void setBonus(double bonus) {
		this.bonus = bonus;
	}

	public String getUserName() {
		return userName;
	}

	public String getName() {
		return name;
	}
	
}
