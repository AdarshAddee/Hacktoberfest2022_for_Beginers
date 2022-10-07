package Linkedlist;

public class palindrome_linkedlist {
    Node head;

    static class Node {
        int data;
        Node next;

        Node(int data) {
            this.data = data;
            this.next = null;
        }
    }

        public Node reverse(Node head)
        {
            if(head==null||head.next==null)
            {return head;}
            Node new_head=reverse(head.next);
            Node headnext=head.next;
            headnext.next=head;
            head.next=null;
            return new_head;
        }
        public Node  middle(Node head)
        {
            Node slow=head;
            Node fast=head;
            while(fast!=null&&fast.next!=null)
            {
             slow=slow.next;
             fast=fast.next.next;

            }
            return slow;
        }
        public boolean ispalindrome(Node head)
        {
            if(head==null||head.next==null)
            {
                return true;
            }
            Node middle_node=middle(head);
            Node first_pointer=head;
            Node last_pointer=reverse(middle_node);
            while(last_pointer!=null) {
                if (first_pointer.data != last_pointer.data) {
                    return false;
                }
                first_pointer = first_pointer.next;
                last_pointer = last_pointer.next;
            }
            return true;





        }

    public static void main(String args[])
    {
        palindrome_linkedlist ll=new palindrome_linkedlist();
        ll.head = new palindrome_linkedlist.Node(1);
        ll.head.next = new palindrome_linkedlist.Node(3);
        ll.head.next.next = new palindrome_linkedlist.Node(2);
        ll.head.next.next.next = new palindrome_linkedlist.Node(4);
        ll.head.next.next.next.next = new palindrome_linkedlist.Node(1);

        System.out.println(ll.ispalindrome(ll.head));

    }
}
