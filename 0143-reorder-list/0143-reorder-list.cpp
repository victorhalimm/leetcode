/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
    public:

    void reorderList(ListNode* head) {
        
        stack<ListNode*> nodes;

        ListNode* dummy = head;

        while (dummy) {

            nodes.push(dummy);
            dummy = dummy->next;

        }

        ListNode* curr = head;

        if (nodes.size() <= 2) return;
        int mid = nodes.size() / 2;


        for (int i = 0; i < mid; i ++) {

            ListNode* temp = curr->next;

            curr->next = nodes.top();
            nodes.top()->next = temp;

            curr = temp;

            nodes.pop();

        }


        if (curr->next)
            curr->next = NULL;


    }


};
