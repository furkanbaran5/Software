package Lab2;

public class Otobus {
	public String otobusNo;
	private Durak[] duraklar = new Durak[3];
	private int durakSayisi=0;
	
	public Otobus(String otobusNo) {
		this.otobusNo = otobusNo;
	}

	public void setOtobusNo(String otobusNo) {
		this.otobusNo = otobusNo;
	}

	public String getOtobusNo() {
		return otobusNo;
	}
	
	public void durakEkle(Durak durak) {
		int i=0,flag=1;
		while(i<duraklar.length && flag==1) {
			if(duraklar[i]==null) {
				duraklar[i]=durak;
				flag=0;
				durakSayisi++;
			}
			i++;
		}
	}
	
	public void durakEkle(Durak durak,int i) {
		duraklar[i]=durak;
	}
	
	public void durakSil(Durak durak) {
		for(int i=0 ; i< duraklar.length ; i++) {
			if(duraklar[i]==durak) {
				duraklar[i]=null;
			}
		}
	}
	
	public void duraklariGoster() {
		for(int i=0; i<duraklar.length ; i++) {
			System.out.println(duraklar[i]);
		}
	}

	public int getDurakSayisi() {
		return durakSayisi;
	}

	public Durak[] getDuraklar() {
		return duraklar;
	}
	
	
}
