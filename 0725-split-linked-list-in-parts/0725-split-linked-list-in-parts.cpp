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
    vector<ListNode*> splitListToParts(ListNode* head, int k) {

        vector<ListNode*> res(k);

        if (head == nullptr) return res;

        ListNode *i = head;
        int size = 0;

        while (i) {
            size ++;
            i = i->next;
        }

        int baseElement = size / k;
        int extra = size % k;

        ListNode *curr = head;

        int it = 0;

        while (curr) {
            int elements = baseElement;

            if (extra > 0) {
                elements ++;
                extra --;
            }

            ListNode *tempHead = curr;

            for (int i = 0; i < elements - 1; i ++) {
                curr = curr->next;
            }

            ListNode *next = curr->next;
            curr->next = nullptr;

            res[it] = tempHead;

            curr = next;
            it ++;
        }

        return res;

    }
};