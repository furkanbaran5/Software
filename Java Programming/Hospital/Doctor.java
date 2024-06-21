package Lab3_a;

import java.util.ArrayList;
import java.util.List;
import java.util.Random;


public class Doctor implements ISurgeon,IMedicalPersonnel {
	private static ArrayList<Doctor> doctorList= new ArrayList<Doctor>(2);
	private String name;
	private double experience=0;
	private int surgeries=2;
	
	
	public Doctor(String name) {
		super();
		this.name = name;
		doctorList.add(this);
	}

	
	public static List<Doctor> getDoctorList() {
		return doctorList;
	}

	Random random = new Random();
	
	@Override
	public void performSurgery() throws SurgeryUnsuccessfulException {
		for (int i = 0; i < surgeries; i++) {
            boolean surgerySuccessful = random.nextDouble() < 0.8; // 80% success rate
            if (surgerySuccessful) {
                experience += 2.5;
            } else {
            	surgeries = 0;
                throw new SurgeryUnsuccessfulException("Surgery by " + name + " was unsuccessful.");
            }
        }
	}


	@Override
	public String getName() {
		return name;
	}
	public double getSurgery() {
		return surgeries;
	}

	@Override
	public String toString() {
		return "Doctor [name=" + name + ", experience=" + experience + ", surgeries=" + surgeries + "]";
	}
	

}
