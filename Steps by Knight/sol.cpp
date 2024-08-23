//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution 
{
    public:
    //Function to find out minimum steps Knight needs to reach target position.
	int minStepToReachTarget(vector<int>&KnightPos,vector<int>&TargetPos,int N)
	{
	    // Code here
	    vector<vector<bool>> visited(N + 1, vector<bool>(N + 1, false));
        int dx[] = {-2, -1, 1, 2, 2, 1, -1, -2};
        int dy[] = {1, 2, 2, 1, -1, -2, -2, -1};
        
        queue<pair<int, pair<int, int>>> q;
        q.push({0, {KnightPos[0], KnightPos[1]}});
        visited[KnightPos[0]][KnightPos[1]] = true;
        
        while (!q.empty()) {
            int steps = q.front().first;
            int x = q.front().second.first;
            int y = q.front().second.second;
            q.pop();
            
            if (x == TargetPos[0] && y == TargetPos[1])
                return steps;
            
            for (int i = 0; i < 8; i++) {
                int nx = x + dx[i];
                int ny = y + dy[i];
                
                if (nx > 0 && ny > 0 && nx <= N && ny <= N && !visited[nx][ny]) {
                    visited[nx][ny] = true;
                    q.push({steps + 1, {nx, ny}});
                }
            }
        }
        
        return -1;
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		vector<int>KnightPos(2);
		vector<int>TargetPos(2);
		int N;
		cin >> N;
		cin >> KnightPos[0] >> KnightPos[1];
		cin >> TargetPos[0] >> TargetPos[1];
		Solution obj;
		int ans = obj.minStepToReachTarget(KnightPos, TargetPos, N);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends
