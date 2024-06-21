package Lab3_a;

import java.util.LinkedList;

public class Patient implements IMedicalPersonnel{
	private String name;
	private LinkedList<Treatment> treatments;
	
	
	public Patient(String name) {
		super();
		this.name = name;
		treatments = new LinkedList<Treatment>();
	}

	public LinkedList<Treatment> getTreatments(){
		return treatments;
	}

	@Override
	public String toString() {
		return "Patient [name=" + name + ", treatments=" + treatments + "]";
	}

	@Override
	public String getName() {
		return null;
	}
	
	

}
