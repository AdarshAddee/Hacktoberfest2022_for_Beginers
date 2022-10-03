import java.util.Scanner;

public class hollowRhombus {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();

        for (int i = 0; i <= n; i++) {
            for (int j = n; j >= i; j--) {
                System.out.print(" ");
            }
            for (int j = 0; j <= i; j++) {
                if (i == n || i == 0 || j == 0) {
                    System.out.print("*");
                } else {
                    System.out.print(" ");
                }
            }
            for (int j = n; j >= i; j--) {
                if (j == 0 || j == 1 || j == i || i == 0) {
                    System.out.print("*");
                } else {
                    System.out.print(" ");
                }
            }
            System.out.println();
        }
        sc.close();

    }
}
