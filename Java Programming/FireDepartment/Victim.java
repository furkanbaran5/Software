package Lab3_b;

import java.util.LinkedList;

public class Victim implements IMedicalPersonnel{
	private String name;
	private LinkedList<EmergencyProcedure> emergencyProcedures;

	public Victim(String name) {
		super();
		this.name = name;
		emergencyProcedures = new LinkedList<EmergencyProcedure>();
	}

	public LinkedList<EmergencyProcedure> getEmergencyProcedure(){
		return emergencyProcedures;
	}

	@Override
	public String toString() {
		return "Victim [name=" + name + "]";
	}

	@Override
	public String getName() {
		return name;
	}

}
