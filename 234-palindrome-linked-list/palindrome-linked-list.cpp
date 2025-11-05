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
// 1, 2, ,3 4 
    ListNode* reverseList(ListNode* head){
        ListNode* prev= NULL;
        ListNode* curr = head; 
        while(curr){
            ListNode* tmp = curr->next; 
            curr->next=prev; 
            prev=curr; 
            curr = tmp;
        }
        return prev; 
    }
    bool isPalindrome(ListNode* head) {
        if(!head) return true; 
        if(!head->next) return true; 

         ListNode* fst = head; 
         ListNode* slw = head; 
         // even , odd
         // even , next 
         // odd  null. 
         while(fst && fst->next){
            fst = fst->next->next; 
            slw = slw->next; 
         }
         if(fst){
            slw = slw->next; 
         } 
            
         ListNode* slww = reverseList(slw); 
         while(slww && head && slww->val == head->val){
            slww = slww->next;
            head= head->next;
         }
         if(slww == NULL) return true; 
         return false; 
    }
};