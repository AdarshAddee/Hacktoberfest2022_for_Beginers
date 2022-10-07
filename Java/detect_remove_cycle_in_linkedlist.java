package Linkedlist;

public class detect_remove_cycle_in_linkedlist {
    Node head;
    static class Node
    {
        Node head;
        int data;
        Node next;
        Node(int data)
        {
            this.data=data;
            this.next=null;
        }


    }
    public Node detect(Node head)
    {
        Node meetpoint=meetnode(head);
        Node firstnode=head;
        while(firstnode!=meetpoint)
        {
            meetpoint=meetpoint.next;
            firstnode=firstnode.next;

        }
        return firstnode;
    }
    public Node meetnode(Node head) {
        Node slow = head;
        Node fast = head;
        while (fast.next != null && fast != null) {
            slow = slow.next;
            fast = fast.next.next;
            if (slow == fast) {
                return slow;
            }

        }
        return null;
    }
    public void delete(Node head)
    {
        Node current_node=detect(head);
        Node temp_node=current_node;;



        while(temp_node.next!=current_node)
        {
            temp_node=temp_node.next;
        }
        temp_node.next=null;
    }
    public void print_after_delete(){
        delete(head);
        Node current_node=head;
        while(current_node!=null)
        {
            System.out.print(current_node.data+"->");
            current_node=current_node.next;
        }
        System.out.print("null");



    }

    public static void main(String args[])
    {
        detect_remove_cycle_in_linkedlist ll=new detect_remove_cycle_in_linkedlist();
        ll.head = new detect_remove_cycle_in_linkedlist.Node(1);
        ll.head.next = new detect_remove_cycle_in_linkedlist.Node(2);
        ll.head.next.next = new detect_remove_cycle_in_linkedlist.Node(3);
        ll.head.next.next.next = new detect_remove_cycle_in_linkedlist.Node(4);
        ll.head.next.next.next.next = new detect_remove_cycle_in_linkedlist.Node(5);
        ll.head.next.next.next.next.next = new detect_remove_cycle_in_linkedlist.Node(6);
        ll.head.next.next.next.next.next.next = ll.head.next.next;
        Node jj=ll.detect(ll.head);
        System.out.println(jj.data);
       ll.print_after_delete();

    }
}
