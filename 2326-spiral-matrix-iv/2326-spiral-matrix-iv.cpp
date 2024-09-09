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
    vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {
        
        vector<vector<int>> res(m, vector<int>(n, -1));

        if (m == 0 || n == 0) return res; // Return if the matrix is empty

        ListNode* curr = head;
        int horizontal = n, vertical = m;

        int startHori = 0, startVert = 0;

        while (curr) {
            int horiIter = startHori;
            int vertIter = startVert;

            for (horiIter = startHori; horiIter < horizontal && curr; horiIter++) {
                res[vertIter][horiIter] = curr->val;
                curr = curr->next;
            }

            horiIter--;
            startVert++;

            for (vertIter = startVert; vertIter < vertical && curr; vertIter++) {
                res[vertIter][horiIter] = curr->val;
                curr = curr->next;
            }

            vertIter--;
            horizontal--;  

            for (horiIter = horizontal - 1; horiIter >= startHori && curr; horiIter--) {
                res[vertIter][horiIter] = curr->val;
                curr = curr->next;
            }

            horiIter++; 
            vertical--;

            for (vertIter = vertical - 1; vertIter >= startVert && curr; vertIter--) {
                res[vertIter][horiIter] = curr->val;
                curr = curr->next;
            }

            startHori++;
        }

        return res;
    }
};