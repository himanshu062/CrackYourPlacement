class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ans;
        unordered_map<string, vector<string>> mpp;

        for (const string& str : strs) {
            string key = str;
            ranges::sort(key);
            mpp[key].push_back(str);
        }

        for (const auto& [_, i] : mpp)
            ans.push_back(i);

        return ans;
    }
};