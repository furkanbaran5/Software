package Lab3_a;

import java.util.ArrayList;
import java.util.List;

public class Hospital {
	private static ArrayList<Doctor> medicalPersonnelList;

	public Hospital() {
		super();
		medicalPersonnelList = new ArrayList<Doctor>(2);
	}
	
	public void addMedicalPersonnel(Doctor personnel) {
		medicalPersonnelList.add(personnel);
	}
	public void assignPatientToDoctor(Doctor doctor,Patient patient, Treatment treatment) {
		try {
			doctor.performSurgery();
			
		} catch (SurgeryUnsuccessfulException e) {
			e.printStackTrace();
		}
	}
	public static <Z> void showList(List<Z> doctor) {
		for(Z x:doctor)
			System.out.println(x);
	}
}
