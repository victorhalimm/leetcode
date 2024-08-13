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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        
        ListNode* currL1 = l1;
        ListNode* currL2 = l2;

        ListNode* result = new ListNode();
        ListNode* resultHead = result;

        int remainder = 0;

        while (currL1 && currL2) {
            int sum = currL1->val + currL2->val + remainder;

            if (sum >= 10) {
                remainder = 1;
                sum -= 10;
            } else remainder = 0;

            currL1 = currL1->next;
            currL2 = currL2->next;

            result->val = sum;

            if (currL1 || currL2) {
                result->next = new ListNode();
                result = result->next;
            }
        }

        if (currL1) passOverFromList(result, currL1, remainder);
        else if (currL2) passOverFromList(result, currL2, remainder);

        else if (remainder) result->next = new ListNode(remainder);

        return resultHead;
    }

    void passOverFromList(ListNode* target, ListNode* source, int remainder) {
        int sum = source->val + remainder;

        if (sum >= 10) {
            remainder = 1;
            sum -= 10;
        } else remainder = 0;
        
        target->val = sum;

        while (source->next) {
            source = source->next;

            target->next = new ListNode();

            target->next->val = source->val + remainder;

            if (target->next->val >= 10) {
                remainder = 1;
                target->next->val -= 10;
            } else remainder = 0;

            target = target->next;
        }

        if (remainder) 
            target->next = new ListNode(remainder);
        
    }
};