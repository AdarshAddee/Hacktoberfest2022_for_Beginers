package Linkedlist;

public class remove_duplicate_in_linkedlist {
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
    public Node remove(Node head)
    { Node current=head;
        while(current.next!=null){
            if(current.data ==current.next.data)
            {
                current.next=current.next.next;
            }
            else {
                current=current.next;
            }
        }
        return head;
    }
    public void printlist(Node head)
    {
        Node current_node=head;
        while(current_node!=null)
        {
            System.out.println(current_node.data);
            current_node=current_node.next;
        }

    }

    public static void main(String[] args) {
        remove_duplicate_in_linkedlist ll=new remove_duplicate_in_linkedlist();
        ll.head = new remove_duplicate_in_linkedlist.Node(1);
        ll.head.next = new remove_duplicate_in_linkedlist.Node(1);
        ll.head.next.next = new remove_duplicate_in_linkedlist.Node(2);
        ll.head.next.next.next = new remove_duplicate_in_linkedlist.Node(3 );
        ll.head.next.next.next.next = new remove_duplicate_in_linkedlist.Node(3);
        Node t=ll.remove(ll.head);
        ll.printlist(t);

    }
}
