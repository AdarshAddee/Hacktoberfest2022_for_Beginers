package Linkedlist;

public class intersection_of_two_sorted_LL {
    Node head;
    static class Node {
        int data;
        Node next;

        Node(int data)
        {
            this.data=data;
            this.next=null;
        }
    }
    public Node getIntersectionNode(Node headA, Node headB) {
        Node d1=headA;
        Node d2=headB;

        while(d1!=d2)
        {

            if(d1==null)
            {
                d1=headB;
                d2=d2.next;
            }

            else if(d2==null)
            {
                d2=headA;
                d1=d1.next;
            }
            else
            {
                d1=d1.next;
                d2=d2.next;
            }
        }
        return d1;

    }
    public static void main(String[] args) {
        intersection_of_two_sorted_LL ll=new intersection_of_two_sorted_LL();
        ll.head = new intersection_of_two_sorted_LL.Node(4);
        ll.head.next = new intersection_of_two_sorted_LL.Node(1);
        ll.head.next.next = new intersection_of_two_sorted_LL.Node(8);

        intersection_of_two_sorted_LL ll2=new intersection_of_two_sorted_LL();
        ll2.head = new intersection_of_two_sorted_LL.Node(5);
        ll2.head.next = new intersection_of_two_sorted_LL.Node(6);
        ll2.head.next.next = new intersection_of_two_sorted_LL.Node(1);
        ll2.head.next.next.next = ll.head.next.next;

        Node t=new intersection_of_two_sorted_LL().getIntersectionNode(ll.head,ll2.head);
        System.out.println(t.data);




    }

}
