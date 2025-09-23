class Solution {
public:
    int compareVersion(string version1, string version2) {
        stringstream version1_ss(version1), version2_ss(version2);

        vector<int> versions_1, versions_2;
        string temp;

        while (getline(version1_ss, temp, '.')) {
            versions_1.push_back(stoi(temp));
        }
        
        while (getline(version2_ss, temp, '.')) {
            versions_2.push_back(stoi(temp));
        }

        int r = 0;
        for (int l = 0; l < versions_1.size(); l ++) {
            int curr_r = r < versions_2.size() ? versions_2[r] : 0;
            
            if (versions_1[l] < curr_r) return -1;
            
            if (versions_1[l] > curr_r) return 1;

            r ++;
        }

        while (r < versions_2.size()) {
            if (versions_2[r] > 0) return -1;
            r ++;
        }
        
        return 0;
    }
};