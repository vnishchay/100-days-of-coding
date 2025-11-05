/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *ha, ListNode *hb) {
        ListNode* headA = ha;
        ListNode* headB = hb;
        int counta = 0;
        int countb = 0;   
        while(headA && headB) {
            if(headA == headB) return headA; 
            headA = headA->next; 
            headB = headB->next;
        }
            while( headA) {
                headA = headA->next; 
                counta +=1; 
            }
            while(hb && headB){
                countb+=1; 
                headB = headB->next; 
            }
        
        if(counta > countb){
            while(counta > countb){
                ha = ha->next; 
                counta--; 
            }
        }else {
            while(countb > counta){
                hb = hb->next; 
                countb--;
            }
        }

        while(ha && hb){
            if(ha == hb) return ha; 
            ha = ha->next; 
            hb = hb->next; 
        }
        return NULL;  
    }
};