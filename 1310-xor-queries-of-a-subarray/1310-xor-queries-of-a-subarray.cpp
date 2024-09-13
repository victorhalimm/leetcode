class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        vector<int> prefix(arr.size());

        if (arr.size() == 0 || queries.size() == 0) return {};

        for (int i = 0; i < arr.size(); i ++) {

            if (i == 0) prefix[i] = arr[i];

            else {
                prefix[i] = prefix[i - 1] ^ arr[i];
            }
        }

        vector<int> res;

        for (vector<int>& query : queries) {

            int left = query[0];
            int right = query[1];
            
            if (left == 0) {
                res.push_back(prefix[right]);
            } else {
                res.push_back(prefix[right] ^ prefix[left - 1]);
            }
        }

        return res;
    }
};