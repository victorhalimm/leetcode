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
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        
        ListNode *curr = head;

        while (curr && curr->next) {
            ListNode *next = curr->next;

            ListNode *node = new ListNode(gcd(curr->val, next->val));

            curr->next = node;
            node->next = next;

            curr = next;
        }

        return head;

    }
};

