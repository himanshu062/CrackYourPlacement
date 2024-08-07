//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution
{
    public:
    //Function to find maximum of minimums of every window size.
    vector <int> maxOfMin(int arr[], int N)
    {
        // Your code here
    vector<int> prev(N, -1), next(N, N);
    stack<int> s;
    for (int i = 0; i < N; i++) {
        while (!s.empty() && arr[s.top()] >= arr[i])
            s.pop();
        if (!s.empty())
            prev[i] = s.top();
        s.push(i);
    }
    while (!s.empty())
        s.pop();
    for (int i = N - 1; i >= 0; i--) {
        while (!s.empty() && arr[s.top()] >= arr[i])
            s.pop();
        if (!s.empty())
            next[i] = s.top();
        s.push(i);
    }
    vector<int> result(N + 1, 0);
    for (int i = 0; i < N; i++) {
        int len = next[i] - prev[i] - 1;
        result[len] = max(result[len], arr[i]);
    }
    for (int i = N - 1; i >= 1; i--)
        result[i] = max(result[i], result[i + 1]);
    vector<int> ans(N);
    for (int i = 1; i <= N; i++)
        ans[i - 1] = result[i];
    
    return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) cin >> a[i];
        Solution ob;
        vector <int> res = ob.maxOfMin(a, n);
        for (int i : res) cout << i << " ";
        cout << endl;
    }
    return 0;
}

// } Driver Code Ends
