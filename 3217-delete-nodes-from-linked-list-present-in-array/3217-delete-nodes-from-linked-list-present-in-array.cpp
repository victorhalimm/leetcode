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
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        
        unordered_set<int> set(nums.begin(), nums.end());

        ListNode* curr = head;
        ListNode* prev = nullptr;

        while (curr && curr->next) {

            ListNode *next = curr->next;
            if (set.find(curr->val) != set.end()) {

                if (!prev) {
                    head = next;
                    curr->next = nullptr;
                    curr = nullptr;

                } else {
                    curr->next = nullptr;
                    prev->next = next;
                    curr = prev;
                    
                }
            }

            prev = curr;
            curr = next;

        }

        if (set.find(curr->val) != set.end()) {
            if (!prev) {
                head = curr->next;
                curr->next = nullptr;

            } else {
                curr->next = nullptr;
                prev->next = curr->next;
            }
        }

        return head;
    }
};