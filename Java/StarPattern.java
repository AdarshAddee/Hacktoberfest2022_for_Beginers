
// Github username: Sneha2319
// Aim: Starpattern in java
// Date: 24-10-2022




public class Main
{
  public static void main(String[] args){
   for(int i=1; i<=4;i++){
        for(int j=1; j<=i;j++){
            System.out.print("*");
        }System.out.println();                     
    }
    for(int i=1; i<=3;i++){
        for(int j=3;j>=i;j--){
            System.out.print("*");
        }System.out.println();
    }
}}

//Output
// *
// **
// ***
// ****
// ***
// **
// *
