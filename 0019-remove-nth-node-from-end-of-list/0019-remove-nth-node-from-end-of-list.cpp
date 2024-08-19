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
    ListNode* removeNthFromEnd(ListNode* head, int n) {

        ListNode* slow = head, *fast = head; 

        for (int i = 0; i < n; i ++) {
            fast = fast->next;
        }

        if (!fast) {
            return head = head->next;
        }

        int count = n + 1;

        while (fast && fast->next != NULL) {
            fast = fast->next;
            slow = slow->next;
            n ++;
        }

        if (slow && slow->next && slow->next->next)
            slow->next = slow->next->next;

        else {
            slow->next = NULL;
        }

        return head;
    }
};
