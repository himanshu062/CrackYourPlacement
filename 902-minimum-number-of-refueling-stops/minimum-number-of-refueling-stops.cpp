class Solution {
public:
    int minRefuelStops(int target, int startFuel,
                       vector<vector<int>>& stations) {
        int ans = 0;
        int i = 0;
        int curr = startFuel;
        priority_queue<int> maxHeap;

        while (curr < target) {
            while (i < stations.size() && curr >= stations[i][0])
                maxHeap.push(stations[i++][1]);
            if (maxHeap.empty())
                return -1;
            curr += maxHeap.top(), maxHeap.pop();
            ++ans;
        }

        return ans;
    }
};