class Solution {
public:
    vector<string> simple_tokenizer(string s)
    {
        vector<string> res; 

        stringstream ss(s);
        string word;
        
        while (ss >> word) {
            res.push_back(word);
        }

        return res;
    }


    vector<string> uncommonFromSentences(string s1, string s2) {
        vector<string> res;

        vector<string> words1 = simple_tokenizer(s1);
        vector<string> words2 = simple_tokenizer(s2);

        for (auto &word : words1) {
            if (count(words2.begin(), words2.end(), word) == 0 && count(words1.begin(), words1.end(), word) == 1) {
                res.push_back(word);
            }
        }

        for (auto &word : words2) {
            if (count(words1.begin(), words1.end(), word) == 0 && count(words2.begin(), words2.end(), word) == 1) {
                res.push_back(word);
            }
        }

        return res;
    }
};