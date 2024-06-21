package Lab3_a;

import java.util.ArrayList;

public class Room {
	private static int nextRoomNumber;
	private int roomNumber;
	private int durationOfStay;
	private ArrayList<Treatment> treatments;
	public Room(int durationOfStay) {
		super();
		this.durationOfStay = durationOfStay;
	}
	public int getRoomNumber() {
		return roomNumber;
	}
	
	public void addTreatment(ArrayList<Treatment> treatment) {
		
	}
	@Override
	public String toString() {
		return "Room [roomNumber=" + roomNumber + ", durationOfStay=" + durationOfStay + ", treatments=" + treatments
				+ "]";
	}
	
}
