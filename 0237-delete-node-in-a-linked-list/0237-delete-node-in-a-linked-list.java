/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */
class Solution {
    public void deleteNode(ListNode node) {
        
     if (node == null) return;
        ;
        if (node.next != null) {
            int nextValue = node.next.val;
            node.next = node.next.next;
            node.val = nextValue;
        }
    }
}