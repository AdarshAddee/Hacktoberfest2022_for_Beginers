import java.util.Arrays;

public class Sieve_of_Eratosthenes
{
    public static boolean[] sieve(int n)
    {
        boolean bool[]=new boolean[n+1];
        Arrays.fill(bool, true);
        bool[0]=false;
        bool[1]=false;

        for (int i = 2; i*i<=n; i++) { //same as i< root n
            for (int j = 2*i; j <=n; j+=i) {
                bool[j]=false;
            }
        }
        return bool;

    }
    public static void main(String[] args) {
        boolean isPrime[]= sieve(12);

        for (int i = 0; i <=12; i++) {
            System.out.println(i+" "+isPrime[i]);
        }

    }
}