class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        if (fruits.size() <= 2) return fruits.size();

        unordered_map<int, int> baskets;
        int maxFruit = 0;

        int l = 0;
        for (int r = 0; r < fruits.size(); r++) {
            baskets[fruits[r]]++;

            while (baskets.size() > 2) {
                baskets[fruits[l]]--;
                if (baskets[fruits[l]] == 0)
                    baskets.erase(fruits[l]);
                l++;
            }

            maxFruit = max(maxFruit, r - l + 1);
        }

        return maxFruit;
    }
};