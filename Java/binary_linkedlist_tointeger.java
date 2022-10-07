package Linkedlist;

public class binary_linkedlist_tointeger {
    Node head;

    static  class Node{
        int data;
        Node next;
        Node(int data)
        {
            this.data=data;
            this.next=null;

        }
    }
    public void bintoint(Node head)
    {
        Node temp=head;
        int len=len(head);
        int res=0;
        int i=len;
        while(temp  !=null&&i-->0)
        {
            int a=  (int)((temp.data)*(Math.pow(2,i)));
            res=res+a;
            temp= temp.next;

        }
        System.out.println(res);
    }
    public int len(Node head)
    {
       Node current_node=head;
       int sum=0;

        while(current_node!=null)
        {
           sum=sum+1;
           current_node=current_node.next;

        }
        return sum;

    }

    public static void main(String[] args) {
        binary_linkedlist_tointeger ll=new binary_linkedlist_tointeger();
        ll.head = new binary_linkedlist_tointeger.Node(1);
        ll.head.next = new binary_linkedlist_tointeger.Node(1);
        ll.head.next.next = new binary_linkedlist_tointeger.Node(1);
        ll.bintoint(ll.head);



    }
}
