//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
	bool isBipartite(int V, vector<int>adj[]){
	    // Code here
	    vector<int> color(V, -1);
        for (int i = 0; i < V; i++) {
            if (color[i] == -1) {  
                if (!bfsCheck(i, adj, color)) {
                    return false;
                }
            }
        }
        return true;
    }

    bool bfsCheck(int node, vector<int> adj[], vector<int>& color) {
        queue<int> q;
        q.push(node);
        color[node] = 0; 

        while (!q.empty()) {
            int current = q.front();
            q.pop();

            for (int neighbor : adj[current]) {
                if (color[neighbor] == -1) {  
                    color[neighbor] = 1 - color[current];
                    q.push(neighbor);
                }
                else if (color[neighbor] == color[current]) {  
                    return false;
                }
            }
        }
        return true;
	}

};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int V, E;
		cin >> V >> E;
		vector<int>adj[V];
		for(int i = 0; i < E; i++){
			int u, v;
			cin >> u >> v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		Solution obj;
		bool ans = obj.isBipartite(V, adj);    
		if(ans)cout << "1\n";
		else cout << "0\n";  
	}
	return 0;
}
// } Driver Code Ends
