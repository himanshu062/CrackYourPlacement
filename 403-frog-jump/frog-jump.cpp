class Solution {
public:
    bool canCross(vector<int>& stones) {
        unordered_map<int, unordered_set<int>> mp;
        mp[1] = {1};
        for (int i = 1; i < stones.size(); ++i) {
            for (auto j : mp[stones[i]]) {
                mp[stones[i] + j].insert(j);
                mp[stones[i] + j + 1].insert(j + 1);
                mp[stones[i] + j - 1].insert(j - 1);
            }
        }
        return mp[stones.back()].size() != 0;
    }
};