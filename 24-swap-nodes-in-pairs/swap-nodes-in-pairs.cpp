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
    ListNode* swapPairs(ListNode* head){
        ListNode dummy(0, head);
        ListNode* aa = &dummy;

        while(head && head->next){
            auto tmp = head; 
            auto tmp2 = head->next; 

            aa->next=tmp2;
            tmp->next=tmp2->next; 
            tmp2->next=tmp; 

            aa = tmp; 
            head= tmp->next; 
        }
        return dummy.next; 
    }
};