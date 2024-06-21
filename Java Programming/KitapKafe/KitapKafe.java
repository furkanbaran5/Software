package Lab2_a;

public class KitapKafe {
	private Masa[] masalar;

	public KitapKafe(int i) {
		this.masalar = new Masa[i];
	}
	
	public boolean yerAyir(Kisi ad) {
		int i=0, j=0;
		while(i<masalar.length && j<masalar[i].getSandalyeler().length) {
			if(masalar[i].getSandalyeler()[j]!=null && masalar[i].getSandalyeler()[j].isDoluluk()==false ) {
				masalar[i].getSandalyeler()[j].setDoluluk(ad.odemeYap(masalar[i].getSandalyeler()[j].getUcret()));
				if(masalar[i].getSandalyeler()[j].isDoluluk()==true) {
					System.out.println(i+". Masa  "+ j + ". sandalyeye atadınız.");
					return true;
				}
			}
			j++;
			if(j==masalar[i].getSandalyeler().length) {
				j=0;
				i++;
			}	
		}
		System.out.println("Boş masa yok");
		return false;
	}
	public void tumMasalariGoster() {
		int i=0,flag=1;
		while(i<masalar.length ) {
			if(masalar[i]!=null) {
				masalar[i].masaDolulukGoster();;
			}
			i++;
		}
	}
	
	public void masaEkle(Masa masa) {
		int i=0,flag=1;
		while(i<masalar.length && flag==1) {
			if(masalar[i]==null) {
				masalar[i]=masa;
				flag=0;
			}
			i++;
		}
		if(flag==1) {
			System.out.println("masada yer olmadıgı için sandalye eklenmiyor");
		}
	}
}
