package Linkedlist;

public class Linkedlist_implementation
{
    private int size;
    Linkedlist_implementation()
    {
        this.size=0;
    }


    Node head;
    class Node{
        String data;
        Node next;
        Node(String data)
        {
            this.data=data;
            this.next=null;
            size++;
        }
    }
    public void addFirst(String data)
    {
        Node new_node=new Node(data);

        if(head==null)
        {
            head=new_node;
            return;

        }
        new_node.next=head;
        head=new_node;

    }
    public void addLast(String data)
    {
        Node new_node=new Node(data);

        if(head==null)
        {
            head=new_node;
            return;

        }
        Node current_node=head;
        while(current_node.next!=null)
        {
            current_node=current_node.next;
        }
        current_node.next=new_node;
    }
    public void deleteFirst()
    {
        if(head==null)
        {
            System.out.println("List is empty");
            return;
        }
        size--;
        head=head.next;
    }
    public void deleteLast()
    {

        if(head==null)
        {
            System.out.println("List is empty");
            return;
        }
        size--;
        if (head.next == null) {
            head=null;
            return;

        }
        Linkedlist_implementation.Node second_last_node=head;
        Linkedlist_implementation.Node last_node=head.next;
        while(last_node.next!=null)
        {
            last_node=last_node.next;
            second_last_node=second_last_node.next;
        }
        second_last_node.next=null;

    }
    public int size()
    {
        return size;
    }



    public void printlist()
    {
        Node current_node=head;


        if(head==null)
        {
            System.out.print("list is empty");
            return;

        }

        while(current_node!=null)
        {
            System.out.print(current_node.data+"->");
            current_node=current_node.next;

        }
        System.out.print("null");
    }
    public static void main(String args[])
    {
        Linkedlist_implementation ll=new Linkedlist_implementation();
        ll.addFirst("a");
        ll.addFirst("is");
        ll.addFirst("this");
        ll.addLast("list");
        ll.printlist();
        ll.deleteFirst();
        System.out.println("");
        ll.printlist();
        ll.deleteLast();
        System.out.println("");
        ll.printlist();
        System.out.println("");
        System.out.println(ll.size());


    }
}
