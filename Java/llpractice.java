package Linkedlist;

import java.util.*;

/*question1:-make ll and add 1,5,7,3,8,2,3 search the no. 7 and display its index
public class Linkedlistfolder.llpractice {
    public static void main(String args[])
    {
        LinkedList<Integer> ll=new LinkedList<Integer>();
        ll.add(1);
        ll.add(5);
        ll.add(7);
        ll.add(3);
        ll.add(8);
        ll.add(2);
        ll.add(3);
        if(ll.contains(7))
        {
            System.out.println(ll.indexOf(7));
        }
    }

}*/
public  class llpractice
{
    public static void main(String args[])
    {
     int n;
     Scanner sc=new Scanner(System.in);
     n=sc.nextInt();
     LinkedList<Integer> ll =new LinkedList<Integer>();
     for(int i=0;i<n;i++)
     {
         ll.add(sc.nextInt());

     }
     Iterator it=ll.iterator();
     while(it.hasNext())
     {
        // if(valueOf(it.next())>25)
        // {
           //  ll.remove();
        // }
     }
     for(int j=0;j<ll.size();j++)
     {
         if(ll.get(j)>25)
         {
             ll.remove(j);
             j=j-1;

         }
     }

     System.out.println(ll);

    }
}


