package Lab2;

public class Iett {
	private Otobus[] otobusler = new Otobus[2];


	
	public Iett(int i) {
		for(int j=0; j<i ; j++) {
			this.otobusler = new Otobus[j];
		}
	}

	public boolean otobusBin(Kisi kisi,Durak durak) {
		int flag=100;
		for(int i=0; i<otobusler.length ; i++) {
			for(int j=0; j<otobusler[i].getDuraklar().length ; j++) {
				if(otobusler[i].getDuraklar()[j]==durak) {
					kisi.odemeYap(otobusler[i].getDuraklar().length);
					flag=i;
				}
			}
			
		}
		if(flag==100) {
			System.out.println("Böyle bir durak yok");
		}else {
			System.out.println(otobusler[flag].otobusNo+" otobusune bindiniz.");
		}
		return false;
	}
	public void tumOtobusleriGoster() {
		for(int i=0; i<otobusler.length ; i++) {
			if(otobusler[i]!=null) {
				System.out.println(otobusler[i].getOtobusNo());
			}
		}
	}

	public void otobusEkle(Otobus otobus) {
		int i=0,flag=1;
		while(i<otobusler.length && flag==1) {
			if(otobusler[i]==null) {
				otobusler[i]=otobus;
				flag=0;
			}
			i++;
		}
	}
	
	
}
