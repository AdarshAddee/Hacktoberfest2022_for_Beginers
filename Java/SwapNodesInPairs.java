// Github username: AlphaVS-76
// Aim: This is a code of swapping nodes in pair in Linked list (with explanation)
// Date: 5th October 2022

class Solution {
    public ListNode swapPairs(ListNode head) {
        //limit - while head != null && if head == null && if head.next == null then return head
        ListNode node = head;
        
        if(node == null){
            return null;
        }
        if(node.next == null){
            return head;
        }
        while(node != null){
            if(node.next == null){
                return head;
            }
            int temp = node.val;
            node.val = node.next.val;
            node.next.val = temp;
            
            node = node.next.next;
        }
        return head;
    }
}
