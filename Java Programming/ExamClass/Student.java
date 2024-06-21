package Lab1_b;

public class Student {
	private int stdNo;
	private String name;
	private int age;
	private double discountPercentage=0;
	private Exam exam ;
	
	public Student(int stdNo, String name, int age) {
		this.stdNo = stdNo;
		this.name = name;
		this.age = age;
	}
	
	public void setExamScore(Exam exam,int note) {
		this.exam=exam;
		exam.setScore(note);
		
	}

	
	@Override
	public String toString() {
		return "Student [stdNo=" + stdNo + ", name=" + name + ", age=" + age + ", discountPercentage="
				+ discountPercentage + ", exam=" + exam + "]";
	}
	
	public void calculateDiscount() {
		if(exam.getScore()>=70) {
			discountPercentage=20;
		}else if(exam.getScore()>=50) {
			discountPercentage=10;
		}
	}

	public int getAge() {
		return age;
	}

	public void setExam(Exam exam) {
		this.exam = exam;
	}

	public double getDiscountPercentage() {
		return discountPercentage;
	}

	
}
