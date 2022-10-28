// Github username:Sujansinh-thakor
// Aim: Custom Linkedlist
// Date: 25-10-2022

// start coding


public class CustomLinkedlist {
    /*   Use in-built linkedlist this just for understanding custom linkedlist      */
    private Node head;
    private Node tail;
    private int size;

    public CustomLinkedlist(){
        this.size=0;
    }
    public void insertlast(int val){
        Node node=new Node(val);
        if (tail==null){
            insertfirst(val);
            return;
        }
        tail.next=node;
        tail=node;
    }
    public void insertfirst(int val){
        Node node=new Node(val);
        node.next=head;
        head=node;
        if (tail==null){
            tail=head;
        }
        size+=1;
    }
    public void deletefirst(){
        Node node=head;
        head=node.next;
        if (tail==null){
            tail=head;
        }
        size-=1;
    }
    public void deletelast(){
        Node node=head;
        if (size<=1){
             deletefirst();
        }
        Node secondlast=get(size);
        int val= tail.value;
        tail=secondlast;
        tail.next=null;

    }
    public int deleteindex(int index){
    if (index==0){
        deletefirst();

    }
    if (index==1){
            deletelast();
    }
    Node previos=get(index-1);
    int val= previos.next.value;
    previos.next=previos.next.next;

    return val;
    }
    public Node get(int index){
        Node node=head;
        for (int i = 0; i < index; i++) {
            node=node.next;
        }
        return node;
    }

    // inserting at particular
    public void insert(int val,int index){
        if (index==0){
            insertfirst(val);
            return;
        }
        if (index==size){
            insertlast(val);
            return;
        }
        //creating temp node which is = to head node
        Node temp=head;
        // running loop until we reach at node which index-1;
        for (int i = 1; i < index; i++) {
            temp=temp.next;
        }
        //then creating node which position temp.next and value is val
        Node node=new Node(val,temp.next);
        //
        temp.next=node;
        
    }
    // insert using recursion
    public void insertRec(int val,int index){
       head=insertRecu(val,index,head); 
    }
    private Node insertRecu(int val,int index,Node node){
        if (index==0){
            Node temp=new Node(val,node );
            size++;
            return temp;
        }
        node.next=insertRecu(val,index--,node.next);
        return node;
    }
    /**                Reverse Link List                     */
    public void reverse(Node node){
            if (node==tail){
                head=tail;
                return;
            }
            reverse(node.next);
            tail.next=node;
            tail=node;
            tail.next=null;
    }
    //displaying linked list
    public void display(){
        Node temp=head;
        while (temp!=null){
            System.out.print(temp.value+" ->");
            temp=temp.next;

        }
        System.out.println("END");

    }

    private class Node {
        private int value;
        private Node next;

        public Node(int value){
            this.value=value;
        }

        public Node(int value, Node next) {
            this.value = value;
            this.next = next;
        }
    }
}
