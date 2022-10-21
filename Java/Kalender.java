import java.util.*;
import java.util.Calendar;

public class Kalender {
	/**
     *
     */
    private static final String MASUKAN_TAHUN_YYYY = "Masukan tahun YYYY: ";

    public static void main(String[] args) {
		Calendar calendar = Calendar.getInstance();  
        System.out.println("Today: " + calendar.getTime());

		Scanner scan = new Scanner(System.in);
		System.out.println("Masukan bulan MM: ");
		int b = scan.nextInt();
		System.out.println(MASUKAN_TAHUN_YYYY);
		int t = scan.nextInt();

		switch (b){
		case 1:
			System.out.println("bulan januari, tahun " + t + " ada 31 hari");
			break;
		case 2:
			if (t%400==0){
				System.out.println("bulan februari, tahun " + t + " ada 29 hari");
			}
			else if (t%400!=0 && t%100==0){
				System.out.println("bulan februari, tahun " + t + " ada 28 hari");
			}
			else if (t%400!=0 && t%100!=0 && t%4==0){
				System.out.println("bulan februari, tahun " + t + " ada 29 hari");
			}
			else{
				System.out.println("bulan februari, tahun " + t + " ada 28 hari");
			}
			break;
		case 3:
			System.out.println("bulan maret, tahun " + t + " ada 31 hari");
			break;
		case 4:
			System.out.println("bulan april, tahun " + t + " ada 30 hari");
			break;
		case 5:
			System.out.println("bulan mei, tahun " + t + " ada 31 hari");
			break;
		case 6:
			System.out.println("bulan juni, tahun " + t + " ada 30 hari");
			break;
		case 7:
			System.out.println("bulan juli, tahun " + t + " ada 31 hari");
			break;
		case 8:
			System.out.println("bulan agustus, tahun " + t + " ada 31 hari");
			break;
		case 9:
			System.out.println("bulan september, tahun " + t + " ada 30 hari");
			break;
		case 10:
			System.out.println("bulan oktober, tahun " + t + " ada 31 hari");
			break;
		case 11:
			System.out.println("bulan november, tahun " + t + " ada 30 hari");
			break;
		case 12:
			System.out.println(" bulan desember, tahun " + t + " ada 31 hari");
			break;
		default:
			System.out.println("error !");
			break;

		}


	}
}