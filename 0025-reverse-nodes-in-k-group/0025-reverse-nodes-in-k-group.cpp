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
    ListNode* reverseKGroup(ListNode* head, int k) {
        
        ListNode *dummy = new ListNode();
        ListNode *prev = NULL;
        ListNode *iter = head;
        ListNode *curr = head;

        int size = 0;

        while (iter != nullptr) {
            iter = iter->next;
            size ++;
        }

        int operations = size / k;

        ListNode *tail = curr;


        for (int it = 0; it < operations; it ++) {
            int i = 0;

            ListNode *group_end = curr;
            
            while (curr != nullptr && i < k) {

                ListNode *next = curr->next;
                curr->next = prev;
                prev = curr;

                curr = next;

                i ++;
            }

            if (it == 0) {
                dummy->next = prev;
            } else {
                tail->next = prev;
            }

            tail = group_end;
        }

        tail->next = curr;

        return dummy->next;

    }
};
