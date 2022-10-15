// Github username: Your RoyIshanBarman
// Aim: printing pyramid pattern
// Date: 15-10-2022
class pyramid{
    public static void main(String args[])
    {
        int i,j,num=1;
        for(i=1;i<=5;i++){
            for(j=1;j<5-i;j++){
                System.out.print("  ");
            }
            for(j=1;j<=i;j++){
                System.out.print(num+"  ");
                num++;
            }
            System.out.println();
        }
    }
}
