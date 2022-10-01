class mergeSortList{
  public static LinkedListNode merge_sorted(
      LinkedListNode head1,
      LinkedListNode head2) {
  
    // if both lists are empty then merged list is also empty
    // if one of the lists is empty then other is the merged list
    if (head1 == null) {
      return head2;
    } else if (head2 == null) {
      return head1;
    }


    LinkedListNode mergedHead = null;
    if (head1.data <= head2.data) {
      mergedHead = head1;
      head1 = head1.next;
    } else {
      mergedHead = head2;
      head2 = head2.next;
    }

    LinkedListNode mergedTail = mergedHead;
  
    while (head1 != null && head2 != null) {
      LinkedListNode temp = null;
      if (head1.data <= head2.data) {
        temp = head1;
        head1 = head1.next;
      } else {
        temp = head2;
        head2 = head2.next;
      }

      mergedTail.next = temp;
      mergedTail = temp;
    }

    if (head1 != null) {
      mergedTail.next = head1;
    } else if (head2 != null) {
      mergedTail.next = head2;
    }

    return mergedHead; 
  
  }
  public static void main(String[] args) {
    int[] arr1 = new int[] {1, 3, 5, 6};
    int[] arr2 = new int[] {2, 4, 6, 20, 34};
    LinkedListNode list_head1 = LinkedList.create_linked_list(arr1);
    System.out.print("Original1: ");
    LinkedList.display(list_head1);

    LinkedListNode list_head2 = LinkedList.create_linked_list(arr2);
    System.out.print("Original2: ");
    LinkedList.display(list_head2);

    System.out.println("\nMerged:");

    LinkedListNode newHead = merge_sorted(list_head1, list_head2);
    LinkedList.display(newHead);
  }
}
