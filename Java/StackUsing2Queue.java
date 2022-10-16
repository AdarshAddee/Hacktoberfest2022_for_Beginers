import java.util.Queue;
import java.util.LinkedList;
public class Stack {

    private Queue q1;
    private Queue q2;


    public Stack() {
        q1=new LinkedList<Integer>();
        q2=new LinkedList<Integer>();
    }



    /*----------------- Public Functions of Stack -----------------*/


    public int getSize() { 
        return q1.size();
    }

    public boolean isEmpty() {
        return q1.size()==0;
    }

    public void push(int element) {
        q1.add(element);
    }

    public int pop() {
        if(q1.size()==0)
        {
            return -1;
        }
        int size=q1.size();
        for(int i=0; i<size-1; i++)
        {
            int ele=(int)q1.poll();
            q2.add(ele);
        }
        int size2=q2.size();
        int ans=(int)q1.poll();
        for(int i=0; i<size2; i++)
        {
            int ele=(int)q2.poll();
            q1.add(ele);
        }
        return ans;

    }

    public int top() {
        if(q1.size()==0)
        {
            return -1;
        }
        int size=q1.size();
        for(int i=0; i<size-1; i++)
        {
            int ele=(int)q1.poll();
            q2.add(ele);
        }
        int ans=(int)q1.poll();
        int size2=q2.size();
        for(int i=0; i<size2; i++)
        {
            int ele=(int)q2.poll();
            q1.add(ele);
        }
        q1.add(ans);
        return ans;
    }
}
