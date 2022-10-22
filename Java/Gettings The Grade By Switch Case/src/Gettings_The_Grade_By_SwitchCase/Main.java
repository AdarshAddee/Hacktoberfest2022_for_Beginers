package Gettings_The_Grade_By_SwitchCase;
import java.util.Scanner;
// Jan 23, 2022
//All Copyright © goes to Hamim Reza Shammo (https://github.com/hrshammo/)
public class Main {

    public static void main(String[] args) {
        int marks;
        Scanner input = new Scanner(System.in);
        System.out.println("Enter the marks:");
        marks = input.nextInt();
        if (marks<=100 && marks>=0){
            switch (marks / 10) {
                case 10:
                case 9:
                    System.out.println("GradeA");
                    break;
                case 8:
                    System.out.println("GradeB");
                    break;
                case 7:
                    System.out.println("GradeC");
                    break;
                case 6:
                    System.out.println("GradeD");
                    break;
                default:
                    System.out.println("GradeF");
            }

        }
        else{
            System.out.println("Invaild marks ");
        }
    }
}
