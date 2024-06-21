package Lab2_a;

public class Masa {
	private Sandalye[] sandalyeler = new Sandalye[3];

	public Masa() {
		
	}
	
	public void sandalyeEkle(Sandalye sandal) {
		int i=0,flag=1;
		while(i<sandalyeler.length && flag==1) {
			if(sandalyeler[i]==null) {
				sandalyeler[i]=sandal;
				flag=0;
			}
			i++;
		}
		if(flag==1) {
			System.out.println("masada yer olmadıgı için sandalye eklenmiyor");
		}
	}
	
	public void sandalyeEkle(Sandalye sandal,int i) {
		sandalyeler[i]=sandal;
	}
	
	public void sandalyeSil(Sandalye sandal) {
		int i=0,flag=1;
		while(i<sandalyeler.length && flag==1) {
			if(sandalyeler[i]==sandal) {
				sandalyeler[i]=null;
				flag=0;
				System.out.println("Sandalye silme işlemi gerçekleşti");
			}
			i++;
		}
	}
	public void masaDolulukGoster() {
		int i=0,flag=1;
		while(i<sandalyeler.length && flag==1) {
			if(sandalyeler[i]!=null) {
				System.out.println(sandalyeler[i]);
				
			}
			i++;
		}
	}

	public Sandalye[] getSandalyeler() {
		return sandalyeler;
	}
	
	
	
}
