class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* curr = head;
        while (curr && curr->next) {
            if (curr->val == curr->next->val) {
                // Duplicate: skip next node
                curr->next = curr->next->next;
            } else {
                curr = curr->next; // Move to next unique value
            }
        }
        return head;
    }
};
