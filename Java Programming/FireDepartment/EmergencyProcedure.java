package Lab3_b;

public class EmergencyProcedure {
	private String procedure;
	private int recoveryPeriodDays;
	private double rescueCost;
	
	public EmergencyProcedure(String procedure, int recoveryPeriodDays, double rescueCost) {
		super();
		this.procedure = procedure;
		this.recoveryPeriodDays = recoveryPeriodDays;
		this.rescueCost = rescueCost;
	}
	@Override
	public String toString() {
		return "EmergencyProcedure [procedure=" + procedure + ", recoveryPeriodDays=" + recoveryPeriodDays
				+ ", rescueCost=" + rescueCost + "]";
	}
	
	
}
