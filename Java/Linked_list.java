/*Creation of linked list using Collection Framework in Java*/
import java.util.*; //Importing util package 
class Linked_list
{    //A java class named Linked_list starts
	public static void main(String args[])
	{      // main method starts
		LinkedList lis= new LinkedList(); //LinkedList method  which is already defined is being invoked and a reference object varaible named lis is being created
    System.out.println("Size of list1 before addition:"+lis.size()); 
		lis.add("A"); //adding the first element to the linked list
		lis.add("B"); //adding the second element to the linked list
		lis.addLast("C"); //adding the third element to the linked list
		lis.addFirst("D"); //adding the fourth element to the linked list
		lis.add(2,"E");  
		System.out.println("Contents of list1:"+lis);
		lis.remove("B"); //removing an element from the linked list
		System.out.println("Contents of list1 after the removal of B:"+lis);
		lis.remove(3);
		System.out.println("Size of list1:"+lis.size());
		lis.removeFirst();
		System.out.println("Contents of list1:"+lis);
		lis.removeLast();
		System.out.println("Contents of list1:"+lis);
    System.out.println("Size of list1:"+lis.size()); //To print the size of the linked list 
		System.out.println(lis);
	} //main method ends
}   // java class named Linked_list ends
