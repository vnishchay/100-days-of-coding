#include <iostream>

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int val) {
        this->val = val;
        next = nullptr; // Use nullptr instead of null
    }
};

// Helper function to reverse a portion of the list from 'start' to 'end'
ListNode* reverseList(ListNode* start, ListNode* end) {
    ListNode* prev = nullptr;
    ListNode* curr = start;
    ListNode* next = nullptr;

    while (curr != end) {
        next = curr->next;  // Save the next node
        curr->next = prev;  // Reverse the link
        prev = curr;        // Move prev to the current node
        curr = next;        // Move to the next node
    }
    return prev;
}

ListNode* reverseListInGroupOfK(ListNode* head, int k) {
    if (!head || k == 1) return head; // No reversal needed for k = 1 or empty list

    ListNode* dummy = new ListNode(0);
    dummy->next = head;
    ListNode* prevGroupEnd = dummy;
    ListNode* curr = head;

    while (curr) {
        // Check if there are at least k nodes left to reverse
        ListNode* groupEnd = curr;
        for (int i = 1; i < k && groupEnd; i++) {
            groupEnd = groupEnd->next;
        }

        if (!groupEnd) break; // If fewer than k nodes remain, stop.

        // Reverse the group
        ListNode* nextGroupStart = groupEnd->next;
        ListNode* newGroupHead = reverseList(curr, groupEnd->next);

        // Link the reversed group to the previous part of the list
        prevGroupEnd->next = newGroupHead;
        curr->next = nextGroupStart;

        // Move prevGroupEnd and curr to the start of the next group
        prevGroupEnd = curr;
        curr = nextGroupStart;
    }

    return dummy->next; // Return the new head of the list
}

// Helper function to print the list
void printList(ListNode* head) {
    while (head) {
        std::cout << head->val << " ";
        head = head->next;
    }
    std::cout << std::endl;
}

// Helper function to create a new node and append to the list
ListNode* appendNode(ListNode* head, int val) {
    if (!head) return new ListNode(val);
    
    ListNode* temp = head;
    while (temp->next) temp = temp->next;
    
    temp->next = new ListNode(val);
    return head;
}

int main() {
    // Create the linked list 1 -> 2 -> 3 -> 4 -> 5 -> 6 -> 7 -> 8
    ListNode* head = nullptr;
    for (int i = 1; i <= 8; i++) {
        head = appendNode(head, i);
    }

    std::cout << "Original list:\n";
    printList(head);

    int k = 3; // Size of the group to reverse
    head = reverseListInGroupOfK(head, k);

    std::cout << "Reversed list in groups of " << k << ":\n";
    printList(head);

    return 0;
}
