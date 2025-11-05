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
    ListNode* kthFromBegining(ListNode* head, int k){
        while(k > 0 && head){
            head = head->next; 
            k --; 
        }
        return head; 
    }
    ListNode* kthFromEnd(ListNode* head, int k){
        ListNode* tmp = head; 
        while(k>0){
            tmp = tmp->next;
            k --;
        }
        while(tmp->next){
            tmp = tmp->next; 
            head = head->next; 
        }
        return head; 
    }
    ListNode* swapNodes(ListNode* head, int k) {
       if(k == 0 ) return head; 
       ListNode* tmp1 = head; 
       ListNode* tmp2 = head;
       tmp2 = kthFromBegining(tmp2, k-1);
       tmp1 = kthFromEnd(tmp1, k-1);
       swap(tmp1->val, tmp2->val); 
       return head; 
    };
};