/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        
     ListNode* slow = head;
        ListNode* fast = head;
        while(fast != NULL && fast ->next != NULL){
            slow = slow->next;
            fast = fast-> next -> next;
        }

        // slow is the middle element


        // Reverse the last half of the linkedlist

        ListNode* prev = NULL;
        ListNode* curr = slow;
        ListNode* nxt;

        while(curr != NULL){
            nxt = curr->next;
            curr->next = prev;

            prev=curr;
            curr=nxt;
        }

        //  prev is pointing to tail
        // so now we will iterate it from head and tail 

        ListNode* temp1 = head;
        ListNode* temp2 = prev;
        while(temp2){
            if(temp1->val != temp2->val){
                return false;
            }
            temp1 = temp1->next;
            temp2 = temp2->next;

        }

        return true;
        
    }
};