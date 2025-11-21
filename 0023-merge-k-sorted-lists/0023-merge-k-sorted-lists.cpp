class Solution {
public:
    struct Compare {
        bool operator()(ListNode* a, ListNode* b) {
            return a->val > b->val;
        }
    };

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*, vector<ListNode*>, Compare> pq;

        // Push the first node of each list
        for(auto node : lists){
            if(node) pq.push(node);
        }

        ListNode* dummy = new ListNode(0);
        ListNode* curr = dummy;

        while(!pq.empty()){
            ListNode* temp = pq.top();
            pq.pop();

            curr->next = temp;
            curr = curr->next;

            if(temp->next){
                pq.push(temp->next);
            }
        }

        return dummy->next;
    }
};
