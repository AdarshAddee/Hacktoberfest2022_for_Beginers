package Linkedlist;

public class Reverselinkedlist {
    Node head;
    static class Node{
        String data;
        Node next;
        Node(String data)
        {
            this.data=data;
            this.next=null;

        }

    }
    public Node reverse(Node head)
    {
        Node current_node=head;
        Node prevnode=null;

        while(current_node!=null)
        {Node tempnode=current_node.next;
            current_node.next=prevnode;
            prevnode=current_node;
            current_node=tempnode;

        }
        return prevnode;
    }
  /*
    RECURSIVE METHOD:-
    public Node reverse(Node head)
    {
        if(head==null||head.next==null)
        {return head;}
        Node new_head=reverse(head.next);
        Node headnext=head.next;
        headnext.next=head;
        head.next=null;
        return new_head;
    }*/
    public void printlist(Node head)
    {
        Node current_node=head;
        while(current_node!=null)
        {
            System.out.println(current_node.data);
            current_node=current_node.next;
        }

    }

    public static void main(String args[])
    {
        Reverselinkedlist ll=new Reverselinkedlist();

        ll.head = new Node("85");
        ll.head.next = new Node("15");
        ll.head.next.next = new Node("4");
        ll.head.next.next.next = new Node("2");
        Node t=ll.reverse(ll.head);
        ll.printlist(t);
    }

    }


