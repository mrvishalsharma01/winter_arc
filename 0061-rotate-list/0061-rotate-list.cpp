class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        
        // Edge case: empty list or single node
        if (head == NULL || head->next == NULL || k == 0) {
            return head;
        }
        
        // Step 1: Find length and last node
        ListNode* temp = head;
        int length = 1;
        
        while (temp->next != NULL) {
            temp = temp->next;
            length++;
        }
        
        // temp is now last node
        
        // Step 2: Reduce k
        k = k % length;
        
        // If k becomes 0, no rotation needed
        if (k == 0) {
            return head;
        }
        
        // Step 3: Make list circular
        temp->next = head;
        
        // Step 4: Find new tail
        int stepsToNewTail = length - k - 1;
        
        ListNode* newTail = head;
        
        for (int i = 0; i < stepsToNewTail; i++) {
            newTail = newTail->next;
        }
        
        // New head
        ListNode* newHead = newTail->next;
        
        // Step 5: Break circle
        newTail->next = NULL;
        
        return newHead;
    }
};