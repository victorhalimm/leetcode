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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        
        ListNode *left_node, *right_node;
        ListNode *curr = head;

        ListNode *prev = nullptr;

        for (int i = 1; i <= right; i ++) {

            if (i == left - 1) 
                prev = curr;

            if (i == left) {
                left_node = curr;
            }
            
            if (i == right)
                right_node = curr;

            curr = curr->next;
        }

        


        ListNode *left_prev = NULL;
        ListNode *head_left = left_node;

        while (left_node != right_node) {

            ListNode *next = left_node->next;

            left_node->next = left_prev;
            left_prev = left_node;

            left_node = next;
        }

        right_node->next = left_prev;

        if (prev)
            prev->next = right_node;

        head_left->next = curr;

        if (head_left == head)
            return right_node;
            
        return head;
    }
};