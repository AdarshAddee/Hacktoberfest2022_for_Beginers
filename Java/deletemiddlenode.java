// Java program to delete middle
// of a linked list
import java.io.*;

class Solution {

	/* Link list Node */
	static class Node {
		int data;
		Node next;
	}

	// Utility function to create a new node.
	static Node newNode(int data)
	{
		Node temp = new Node();
		temp.data = data;
		temp.next = null;
		return temp;
	}

	// count of nodes
	static int countOfNodes(Node head)
	{
		int count = 0;
		while (head != null) {
			head = head.next;
			count++;
		}
		return count;
	}

	// Deletes middle node and returns
	// head of the modified list
	static Node deleteMid(Node head)
	{
		// Base cases
		if (head == null)
			return null;
		if (head.next == null) {
			return null;
		}
		Node copyHead = head;

		// Find the count of nodes
		int count = countOfNodes(head);

		// Find the middle node
		int mid = count / 2;

		// Delete the middle node
		while (mid-- > 1) {
			head = head.next;
		}

		// Delete the middle node
		head.next = head.next.next;

		return copyHead;
	}

	// A utility function to print
	// a given linked list
	static void printList(Node ptr)
	{
		while (ptr != null) {
			System.out.print(ptr.data + "->");
			ptr = ptr.next;
		}
		System.out.println("NULL");
	}

	/* Driver code*/
	public static void main(String[] args)
	{
		/* Start with the empty list */
		Node head = newNode(1);
		head.next = newNode(2);
		head.next.next = newNode(3);
		head.next.next.next = newNode(4);

		System.out.println("Given Linked List");
		printList(head);

		head = deleteMid(head);

		System.out.println(
			"Linked List after deletion of middle");
		printList(head);
	}
}

// This code is contributed by Github - SanketJ29
