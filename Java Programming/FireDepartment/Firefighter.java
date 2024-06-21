package Lab3_b;

import java.util.ArrayList;
import java.util.List;
import java.util.Random;

public class Firefighter implements IRescuer,IMedicalPersonnel {
	private static ArrayList<Firefighter> firefighterList=new ArrayList<Firefighter>(2);;
	private String name;
	private double experience=0;
	private int interventions=0;

	
	public Firefighter(String name) {
		super();
		this.name = name;
		firefighterList.add(this);
	}
	
	public static List<Firefighter> getFirefighterList(){
		return firefighterList;
	}
	
	public double getInterventions() {
		return interventions;
	}

	@Override
	public String toString() {
		return "Firefighter [name=" + name + ", experience=" + experience + ", interventions=" + interventions + "]";
	}

	@Override
	public String getName() {
		return name;
	}
	Random random = new Random();
	@Override
	public void performRescue() throws RescueUnsuccessfulException {
		double basari=random.nextDouble();
		int basarisizlik=0;
		if(basari<=0.8 && basarisizlik==0) {
			System.out.println();
			experience+=2.5;
			interventions++;
		}else if(basarisizlik==0){
			basarisizlik=1;
			throw new RescueUnsuccessfulException(name+" tarafından başarısız Kurtarma");
		}
		
	}

}
