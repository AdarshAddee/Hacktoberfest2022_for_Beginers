// Github username: AlphaVS-76
// Aim: this code implements removing Nth node from the end of list in java
// Date: 5th October 2022

class Solution {
    public ListNode removeNthFromEnd(ListNode head, int n) {
        //getting the length of the list
        int c = 0;
        ListNode list = head; 
        while(list != null) { 
            list = list.next; 
            c++;  
        }
        
        int diff = c-n;  
        //if length and n is same, the first node is eliminated
        if(diff == 0) {        
            return head.next; 
        }
        
        ListNode temp = head; 
        //deleting the (diff-1)th node
        while(diff > 1) {
            diff--;
            temp = temp.next;  
        }
        temp.next = temp.next.next;                                 
        
        return head;
    }
}
