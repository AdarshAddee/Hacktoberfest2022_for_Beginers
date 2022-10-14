// Github username: RashmiNirasha
// Aim: Printing a pattern using loops by java
// Date: 2022/10/14

public class Pattern {
        public static void main(String args[])
        {

            int i, j, row=5;
            for(i=0; i<row; i++)
            {
                for(j=0; j<=i; j++)
                {
                    System.out.print("@" +
                            " ");
                }
                System.out.println();
            }
        }
    }

