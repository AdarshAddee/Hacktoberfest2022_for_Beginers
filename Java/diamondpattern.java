
// github username : DishaKhanapurkar
// aim : diamond pattern program in java
//date : 20.10.22

import java.io.*;
 
// Main class
public class GFG {
 
    // Main driver method
    public static void main(String[] args)
    {
        
        int number = 7;
        int m = 1
        int n;
        do {
            n = 1;

            do {
               
                System.out.print(" ");
 
            }
            while (++n <= number - m + 1);

            n = 1;
 
            do {

                System.out.print("*");
            }
 
            // Condition for inner do-while loop 2
            while (++n <= m * 2 - 1);
 
            // A new row requires a new line
            System.out.println();
 
        }
 
        // Condition for outer do-while loop 1
        while (++m <= number);
        m = number - 1;
 
        // Outer loop 2
        // Prints the second half diamond
        do {
            n = 1;
 
        
            do {
                // Print whitespace between
                System.out.print(" ");
 
            } while (++n <= number - m + 1);
 
            n = 1;
 
         
            do {
                // Prints star
                System.out.print("*");
 
            } while (++n <= m * 2 - 1);
 
           
            System.out.println();
 
        }
        while (--m > 0);
    }
}
