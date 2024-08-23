//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
	void dfs(int node, vector<vector<int>>& adj, vector<bool>& visited, stack<int>& st) {
        visited[node] = true;
        for (int neighbor : adj[node]) {
            if (!visited[neighbor]) {
                dfs(neighbor, adj, visited, st);
            }
        }
        st.push(node);
    }
    void reverseDFS(int node, vector<vector<int>>& transpose, vector<bool>& visited) {
        visited[node] = true;
        for (int neighbor : transpose[node]) {
            if (!visited[neighbor]) {
                reverseDFS(neighbor, transpose, visited);
            }
        }
    }
	//Function to find number of strongly connected components in the graph.
    int kosaraju(int V, vector<vector<int>>& adj)
    {
        //code here
        stack<int> st;
        vector<bool> visited(V, false);
        for (int i = 0; i < V; i++) {
            if (!visited[i]) {
                dfs(i, adj, visited, st);
            }
        }
        vector<vector<int>> transpose(V);
        for (int i = 0; i < V; i++) {
            for (int neighbor : adj[i]) {
                transpose[neighbor].push_back(i);  
            }
        }
        fill(visited.begin(), visited.end(), false);  
        int sccCount = 0;
        
        while (!st.empty()) {
            int node = st.top();
            st.pop();
            if (!visited[node]) {
                sccCount++;
                reverseDFS(node, transpose, visited);
            }
        }
        
        return sccCount;
    }
};

//{ Driver Code Starts.


int main()
{
    
    int t;
    cin >> t;
    while(t--)
    {
    	int V, E;
    	cin >> V >> E;

    	vector<vector<int>> adj(V);

    	for(int i = 0; i < E; i++)
    	{
    		int u, v;
    		cin >> u >> v;
    		adj[u].push_back(v);
    	}

    	Solution obj;
    	cout << obj.kosaraju(V, adj) << "\n";
    }

    return 0;
}


// } Driver Code Ends
