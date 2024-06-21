package Lab3_a;

public class Treatment {
	private String medication;
	private int resPeriodDays;
	private double surgeryCost;
	public Treatment(String medication, int resPeriodDays, double surgeryCost) {
		super();
		this.medication = medication;
		this.resPeriodDays = resPeriodDays;
		this.surgeryCost = surgeryCost;
	}
	@Override
	public String toString() {
		return "Treatment [medication=" + medication + ", resPeriodDays=" + resPeriodDays + ", surgeryCost="
				+ surgeryCost + "]";
	}
	
}
