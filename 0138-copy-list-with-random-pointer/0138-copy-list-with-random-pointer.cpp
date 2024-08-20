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

        if (!head) return NULL;
        
        Node *new_head = new Node(head->val);

        Node *prev = new_head;

        Node *curr = head->next;

        vector<Node*> old_list;
        vector<Node*> new_list;

        old_list.push_back(head);
        new_list.push_back(prev);


        while (curr) {
            prev->next = new Node(curr->val);

            old_list.push_back(curr);
            new_list.push_back(prev->next);

            curr = curr->next;
            prev = prev->next;
        }


        Node *new_curr = new_head;
        Node *old_curr = head;

        while (new_curr && old_curr) {

            if (old_curr->random == NULL) {
                new_curr = new_curr->next;
                old_curr = old_curr->next;
                continue;
            }

            vector<Node*>::iterator it = find(old_list.begin(), old_list.end(), old_curr->random);

            if (it != old_list.end()) {
                int idx = it - old_list.begin();
                new_curr->random = new_list[idx];
            } else new_curr->random = NULL;

            new_curr = new_curr->next;
            old_curr = old_curr->next;

        }

        return new_head;

    }
};
