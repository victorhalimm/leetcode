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
    ListNode* mergeKLists(vector<ListNode*>& lists) {

        if (lists.empty()) return nullptr;

        int size = lists.size();
        vector<ListNode *> iters = lists;

        ListNode *dummy = new ListNode();
        ListNode *dummy_head = dummy;

        bool list_exists = true;

        while (list_exists) {

            ListNode *min = new ListNode(10005);
            int idx = -1;
            int invalid = 0;

            for (int i = 0; i < lists.size(); i ++) {
                if (lists[i] == nullptr) {
                    invalid ++;
                    continue;
                }

                if (lists[i]->val < min->val) {
                    min = lists[i];
                    idx = i;
                }
            }

            if (invalid == size || idx == -1) {
                return dummy_head->next;
            }

            if (min->val != 10005) {
                dummy->next = min;
                dummy = dummy->next;
            }

            if (lists[idx]->next)
                lists[idx] = lists[idx]->next;
            else lists[idx] = nullptr;
        }

        return dummy_head->next;
    }
};