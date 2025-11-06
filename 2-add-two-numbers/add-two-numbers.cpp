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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry =0;
        ListNode* ll = new ListNode(0); 
        ListNode* l0 = ll; 
        while(l1 || l2 || carry) {
            int total= 0;
            if(l1 && l2){
                total = l1->val + l2->val+ carry;
                l1=l1->next;
                l2=l2->next;
            }
            else if(l1) {
                total = l1->val + carry; 
                l1=l1->next;
            }
            else if(l2){
                 total = l2->val + carry; 
                 l2 = l2->next; 
            }else if(carry){
                total += carry; 
            }
            carry = total / 10;  
            int val = total%10; 
            ll->next = new ListNode(val); 
            ll = ll->next;  
        }
        return l0->next; 
    }
};