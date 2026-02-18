class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        
        // Step 1: Create dummy node
        // This simplifies handling of head
        ListNode* dummy = new ListNode(0);
        
        // Tail pointer to build merged list
        ListNode* tail = dummy;
        
        // Step 2: Traverse both lists
        while (list1 != NULL && list2 != NULL) {
            
            // Compare values
            if (list1->val <= list2->val) {
                
                // Attach list1 node
                tail->next = list1;
                
                // Move list1 forward
                list1 = list1->next;
            }
            else {
                
                // Attach list2 node
                tail->next = list2;
                
                // Move list2 forward
                list2 = list2->next;
            }
            
            // Move tail forward
            tail = tail->next;
        }
        
        // Step 3: Attach remaining part
        // Only one of these will run
        
        if (list1 != NULL) {
            tail->next = list1;
        }
        else {
            tail->next = list2;
        }
        
        // Return merged list head
        return dummy->next;
    }
};