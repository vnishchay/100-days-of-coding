class Solution {
public:
    // This returns the node before the N-th node from the end.
    ListNode* findNthNode(ListNode* head, int n ){
        ListNode* lead = head; 
        // Advance lead n steps forward
        for(int i=0;i<n;i++) {
            if (lead) lead = lead->next;
            else return nullptr; // list shorter than n
        }
        ListNode* prev = nullptr;
        ListNode* curr = head;
        // Move both pointers until lead reaches end
        while(lead){
            lead = lead->next;
            prev = curr;
            curr = curr->next;
        }
        // prev now points to node before the one to remove
        return prev;
    }

    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(!head) return nullptr;
        ListNode dummy(0, head); // use dummy for head removal edge case
        ListNode* prev = findNthNode(&dummy, n);
        if(prev && prev->next) {
            ListNode* nodeToRemove = prev->next;
            prev->next = nodeToRemove->next;
            // Optionally: delete nodeToRemove;
        }
        return dummy.next;
    }
};
