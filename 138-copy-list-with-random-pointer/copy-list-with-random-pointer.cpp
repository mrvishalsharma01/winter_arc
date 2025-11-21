/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
    if(!head) return nullptr;

    Node* curr = head;

    // STEP 1: Clone nodes and insert them in between
    while(curr){
        Node* nextNode = curr->next;
        Node* copy = new Node(curr->val);

        curr->next = copy;
        copy->next = nextNode;

        curr = nextNode;
    }

    // STEP 2: Assign random pointers
    curr = head;
    while(curr){
        if(curr->random)
            curr->next->random = curr->random->next;
        curr = curr->next->next;
    }

    // STEP 3: Separate original and copied list
    curr = head;
    Node* dummy = new Node(0);
    Node* copyCurr = dummy;

    while(curr){
        copyCurr->next = curr->next;
        curr->next = curr->next->next;

        curr = curr->next;
        copyCurr = copyCurr->next;
    }

    return dummy->next;
}

};