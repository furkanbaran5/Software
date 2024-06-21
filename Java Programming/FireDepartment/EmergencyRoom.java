package Lab3_b;

import java.util.ArrayList;

public class EmergencyRoom {
	private static int nextEmergencyRoomNumber=100;
	private int emergencyRoomNumber=100;
	private int durationOfStay;
	private ArrayList<EmergencyProcedure> emergencyProcedures;
	public EmergencyRoom(int durationOfStay) {
		this.durationOfStay = durationOfStay;
		emergencyRoomNumber=nextEmergencyRoomNumber++;
		emergencyProcedures = new ArrayList<EmergencyProcedure>();
	}
	
	public int getEmergencyRoomNumber() {
		return emergencyRoomNumber;
	}
	
	public void addEmergencyProcedure(EmergencyProcedure emergencyProcedure) {
		emergencyProcedures.add(emergencyProcedure);
	}
	
	@Override
	public String toString() {
		return "EmergencyRoom [emergencyRoomNumber=" + emergencyRoomNumber + ", durationOfStay=" + durationOfStay
				+ ", emergencyProcedures=" + emergencyProcedures + "]";
	}
	
	
}
