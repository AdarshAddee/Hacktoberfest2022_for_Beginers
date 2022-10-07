package Linkedlist;

public class remove_particular_element_in_LL {
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
    {
        Node current=head;
        while(current.next!=null){
            if(head==null)
            {
                return  null;
            }
            if(head.data==6)
            {
                head=head.next;
            }
            if(current.next.data==6)
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
        remove_particular_element_in_LL ll=new remove_particular_element_in_LL();
        ll.head = new remove_particular_element_in_LL.Node(6);
        ll.head.next = new remove_particular_element_in_LL.Node(6);
        ll.head.next.next = new remove_particular_element_in_LL.Node(2);
        ll.head.next.next.next = new remove_particular_element_in_LL.Node(3 );
        ll.head.next.next.next.next = new remove_particular_element_in_LL.Node(6);
        remove_particular_element_in_LL.Node t=ll.remove(ll.head);
        ll.printlist(t);

    }
}
