class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<bool>> visited(n, vector<bool>(n, false));
        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>,
                       greater<tuple<int, int, int>>>
            pq;
        vector<pair<int, int>> directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        pq.push({grid[0][0], 0, 0});
        visited[0][0] = true;

        while (!pq.empty()) {
            auto [current_max_height, row, col] = pq.top();
            pq.pop();
            if (row == n - 1 && col == n - 1) {
                return current_max_height;
            }
            for (auto& [dr, dc] : directions) {
                int new_row = row + dr;
                int new_col = col + dc;
                if (new_row >= 0 && new_row < n && new_col >= 0 &&
                    new_col < n && !visited[new_row][new_col]) {
                    visited[new_row][new_col] = true;
                    pq.push({max(current_max_height, grid[new_row][new_col]),
                             new_row, new_col});
                }
            }
        }
        return -1;
    }
};