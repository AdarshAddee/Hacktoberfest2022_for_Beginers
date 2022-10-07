package Linkedlist;

public  class merge_two_sorted_linkedlist {
    Node head;
    static class Node
    {
        int data;
        Node next;
        Node(int data)
        {
            this.data=data;
            this.next=null;
        }
    }
    public Node merge(Node head1,Node head2) {
        Node l1 = head1;
        Node l2 = head2;

        while (l1.next != null && l2.next != null)
        {

            Node temp = null;
            while (l1.data <= l2.data&&l1.next!=null) {
                temp=l1;
                l1 = l1.next;

            }
            temp.next = l2;
            Node aisi = l1;
            l1 = l2;
            l2 = aisi;

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
        merge_two_sorted_linkedlist ll=new merge_two_sorted_linkedlist();
        ll.head = new merge_two_sorted_linkedlist.Node(1);
        ll.head.next = new merge_two_sorted_linkedlist.Node(7);
        ll.head.next.next = new merge_two_sorted_linkedlist.Node(9 );
        merge_two_sorted_linkedlist ll2=new merge_two_sorted_linkedlist();
        ll2.head = new merge_two_sorted_linkedlist.Node(3);
        ll2.head.next = new merge_two_sorted_linkedlist.Node(4);
        ll2.head.next.next = new merge_two_sorted_linkedlist.Node(8 );
        ll2.head.next.next.next = new merge_two_sorted_linkedlist.Node(10 );
        Node j=new merge_two_sorted_linkedlist().merge(ll.head,ll2.head);
        ll.printlist(j);



    }
}
