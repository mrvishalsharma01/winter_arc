class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (!head) return nullptr;

        // Step 1: Check if we have at least k nodes
        ListNode* temp = head;
        for (int i = 0; i < k; i++) {
            if (!temp) return head; // not enough nodes
            temp = temp->next;
        }

        // Step 2: Reverse first k nodes
        ListNode* prev = nullptr;
        ListNode* curr = head;
        ListNode* next = nullptr;
        int count = 0;

        while (curr && count < k) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
            count++;
        }

        // Step 3: head is now the last node of the reversed group
        // connect to next groups
        head->next = reverseKGroup(curr, k);

        // prev is new head of this reversed group
        return prev;
    }
};
