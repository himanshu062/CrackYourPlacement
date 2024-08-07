//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution 
{
    public:
    //Function to find minimum time required to rot all oranges. 
    int orangesRotting(vector<vector<int>>& grid) {
        // Code here
        int dr[] = {-1, 0, 1, 0};  
    int dc[] = {0, -1, 0, 1};
    
     int R = grid.size(), C = grid[0].size();
     
     queue<pair<int,int> >q;
     
     for (int r = 0; r < R; ++r)
            for (int c = 0; c < C; ++c)
                if (grid[r][c] == 2) {
                    int code = r * C + c;
                    q.push(make_pair(code,0)); 
                }
 
    int ans = 0;
        while (!q.empty()) {
            pair<int,int> code = q.front();
            q.pop();
            int r = code.first / C, c = code.first % C;
            for (int k = 0; k < 4; ++k) {
                int nr = r + dr[k];
                int nc = c + dc[k];
                if (0 <= nr && nr < R && 0 <= nc && nc < C && grid[nr][nc] == 1) {
                    grid[nr][nc] = 2;
                    int ncode = nr * C + nc;
                    q.push(make_pair(ncode,code.second+1));
                    ans = code.second+1;
                }
            }
        }
        
        for (int i=0;i<R;i++)
            for (int j=0;j<C;j++)
                if (grid[i][j] == 1)
                    return -1;
        
		return ans;
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>grid(n, vector<int>(m, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		int ans = obj.orangesRotting(grid);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends
