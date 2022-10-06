/** 
Question : Take a 4 digit number. Write a program to display a number whose digits are 2 greater than the corresponding digits of the number TAKEN.
For example, if the number which was taken is 5696, then the displayed number should be 7818

**/
import java.util.Scanner;

public class TwentyFive {
public static void main(String[] args) {
    Scanner sc = new Scanner(System.in)
    
    // Only 4 digit number is allowed
    int a = sc.nextInt();

    int first  = a/1000+2;
    
    // Checking if the digit is a single digit or greater | if greater that code will make it single digit 
  
    if (first >= 10){
        first = first/10;
    }
    // if any number is divided by 1000 and then +2 it will + the first digit of the no.


    // Modulus is a math operation that finds the remainder when one integer is divided by another.
    int b = a%1000;
    

    int second = b/100+2;
  
    if (second >= 10){
        second = second/10;
    }

    int c = b%100;

    int third = c/10 + 2;
    if (third >= 10){
        third = third/10;
    }

    int d = c%10;

    int fourth = d+2;
    if (fourth >= 10){
        fourth = fourth/10;
    }
    String result = Integer.toString(first)+Integer.toString(second)+Integer.toString(third)+Integer.toString(fourth);

    System.out.println(result);

}

}
