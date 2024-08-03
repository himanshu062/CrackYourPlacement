//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution
{
    public:
    //Function to find the largest number after k swaps.
void solve(string &str, int k, string &maxStr, int index) {
    if (k == 0) 
        return; 
    int n = str.size();
    char maxChar = str[index];
    for (int i = index + 1; i < n; i++) {
        if (str[i] > maxChar) 
            maxChar = str[i];
    }
    if (maxChar != str[index]) 
        k--; 
    for (int i = index; i < n; i++) {
        if (str[i] == maxChar) {
            swap(str[index], str[i]);
            if (str.compare(maxStr) > 0) 
                maxStr = str;
            solve(str, k, maxStr, index + 1);
            swap(str[index], str[i]);
        }
    }
}
string findMaximumNum(string str, int k) {
    string res = str;
    solve(str, k, res, 0);
    return res;
    }
};

//{ Driver Code Starts.

int main()
{
    int t, k;
    string str;

    cin >> t;
    while (t--)
    {
        cin >> k >> str;
        Solution ob;
        cout<< ob.findMaximumNum(str, k) << endl;
    }
    return 0;
}

// } Driver Code Ends
