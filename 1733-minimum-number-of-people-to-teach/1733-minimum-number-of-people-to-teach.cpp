class Solution {
public:
    int minimumTeachings(int n, vector<vector<int>>& languages, vector<vector<int>>& friendships) {
        unordered_set<int> candidates;
        for (vector<int>& friendship: friendships) {
            unordered_set<int> a;

            int friendA = friendship[0] - 1;
            int friendB = friendship[1] - 1;

            for (int num: languages[friendA]) {
                a.insert(num);
            }

            bool canCommunicate = false;
            for (int num: languages[friendB]) {
                if (a.count(num)) {
                    canCommunicate = true;
                    break;
                }
            }

            if (!canCommunicate) {
                candidates.insert(friendA);
                candidates.insert(friendB);
            }
        }

        vector<int> count(n + 1, 0);
        for (int friendIdx: candidates) {
            for (int lang: languages[friendIdx]) {
                count[lang] ++;
            }
        }

        int mostShared = *max_element(count.begin(), count.end());

        return candidates.size() == 0 ? 0 : candidates.size() - mostShared; 
    }
};