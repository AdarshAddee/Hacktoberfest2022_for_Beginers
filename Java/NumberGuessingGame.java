import java.util.*;

class random
{

    private int n;

    public int ran()
    {
        Random num = new Random();
        return num.nextInt(10);
    }
    
    public int takeUserInput()
    {
        Scanner in = new Scanner(System.in);
        int i= in.nextInt();
        return i;
    }

    public int setCounter()
    {
        return n=0;
    }

    public int setter_numberOfGuesses(int g)
    {
        return n=++g;
    }

    public int getter_numberOfGuesses()
    {
        return n;
    }

    public boolean isCorrectNumber(int uno,int rno,int gno)
    {
        if(uno==rno)
        {
            System.out.printf((gno==1)?"\nWohoo!!!\nYou nailed it in your first shot.\n\n":"\nCongratulations! \nYou guessed the corrrect number in %d attempts.\n\n",gno);
            return true;
        }
        else
        {
            System.out.println((uno>rno)?"\nYour number is larger than the actual number\nTry Again!":"\nYour number is smaller than the actual number\nTry Again!");
            System.out.println();
            return false;
        }
    }

}

public class NumberGuessingGame {
    public static void main(String[] args) {
        System.out.println("\nEnter a single-digit number:");
        random r = new random();
        int gno=r.setCounter(),uno;
        int rno=r.ran();
        // //cheat
        // System.out.println("The actual number choosen by computer is "+rno);
        // // A gift from ADARSH.
        

        do {
            uno=r.takeUserInput();
            gno=r.setter_numberOfGuesses(gno);
            gno=r.getter_numberOfGuesses();
            
        }
        while(!(r.isCorrectNumber(uno,rno,gno)));

    }
}
