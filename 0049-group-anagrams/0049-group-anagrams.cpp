class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> mp;

        for (int i = 0; i < strs.size(); i++) {
            string key = strs[i];          // copy original
            sort(key.begin(), key.end());  // sort copy
            mp[key].push_back(strs[i]);    // store original
        }

        vector<vector<string>> res;
        for (auto& it : mp) {
            res.push_back(it.second);
        }

        return res;
    }
};
