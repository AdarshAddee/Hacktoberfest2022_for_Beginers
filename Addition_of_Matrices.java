public class Addition_of_Matrices
{
    public static void main(String[] args) {
        int a[][]={{2,2,3},{4,5,6}};
        int b[][]={{6,5,4},{3,8,7}};
        int res[][]={{0,0,0},{0,0,0}};
        for(int i=0; i<a.length; i++)
        {
            for(int j=0; j<a[i].length; j++)
            {
                res[i][j]=a[i][j]+b[i][j];
                System.out.print(res[i][j]+" ");
            }           
            System.out.println();
        }
    }
}