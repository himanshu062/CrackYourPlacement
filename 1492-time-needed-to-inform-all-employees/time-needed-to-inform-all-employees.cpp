class Solution {
public:
    int dfs(int node, vector<vector<int>>& tree, vector<int>& informTime) {
        int maxTime = 0;
        for (int subordinate : tree[node]) {
            maxTime = max(maxTime, dfs(subordinate, tree, informTime));
        }
        return informTime[node] + maxTime;
    }
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        vector<vector<int>> tree(n);
        for (int i = 0; i < n; i++) {
            if (manager[i] != -1) {
                tree[manager[i]].push_back(i); 
            }
        }
        return dfs(headID, tree, informTime);
    }
};