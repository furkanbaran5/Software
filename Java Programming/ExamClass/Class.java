package Lab1_b;

public class Class {
	private String name;
	private int duration;
	private String instructor;
	private Student[] st = new Student[2];
	private double averageAge=0;
	private int studentCount=0;
	
	
	public Class(String name, int duration, String instructor) {
		this.name = name;
		this.duration = duration;
		this.instructor = instructor;
	}
	
	public void addStudent(Student std) {
		int i=0,flag=1;
		while(i< st.length && flag==1) {
			if(st[i]==null) {
				st[i]=std;
				flag=0;
				averageAge+=st[i].getAge();
				studentCount++;
			}
			i++;
		}
		if(flag==1) {
			System.out.println("Course capacity is full");
		}
	}
	
	public void classInfo() {
		averageAge/=studentCount;
		System.out.println("Class name:"+ name + "\tNumber of students:" + studentCount +
							"\tAverage age:"+ averageAge);
	}
}
