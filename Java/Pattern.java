// Github username: MananSharma2710
// Aim: To print pattern usin java
// Date: 09-October-2022

// start coding

import java.util.*;

class Pattern {
    public static void main(String[] args) {
        Scanner sc= new Scanner(System.in);
        int n=sc.nextInt();
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=i;j++)
            {
                System.out.print("*");
            }
            System.out.println();
        }
    }
}