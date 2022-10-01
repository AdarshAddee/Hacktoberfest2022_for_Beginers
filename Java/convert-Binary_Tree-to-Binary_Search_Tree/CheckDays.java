import java.util.Scanner;

public class CheckDays {
    public static void main(String[] args) {

        Scanner input = new Scanner(System.in);

        System.out.println("# Determining the Name of the Day #");
        System.out.println("===================================");
        System.out.println();

        int n;

        System.out.print("Enter the number of days (1-7): ");
        n = input.nextInt();

        String[] day = {
                "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday", "Sunday"
        };

        if ((n < 1) || (n > 7)) {
            System.out.println("Options not available");
        } else {
            System.out.println(day[n - 1]);
        }
    }
}
