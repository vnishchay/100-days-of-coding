class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode dummy(0);                  // Dummy node to start the merged list
        ListNode* tail = &dummy;
        
        while (list1 && list2) {
            if (list1->val < list2->val) {
                tail->next = list1;         // Link the smaller node
                list1 = list1->next;        // Move pointer forward
            } else {
                tail->next = list2;
                list2 = list2->next;
            }
            tail = tail->next;              // Advance the tail
        }
        // Attach the remaining nodes, if any
        if (list1) tail->next = list1;
        else tail->next = list2;
        
        return dummy.next;                  // Return head of merged list (skip dummy node)
    }
};
