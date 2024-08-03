//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    vector<vector<string>> allPalindromicPerms(string s) {
        // code here
    vector<vector<string>> result;
    vector<string> currentPartition;
    function<void(int)> backtrack = [&](int start) {
        if (start == s.size()) {
            result.push_back(currentPartition);
            return;
        }
        for (int end = start; end < s.size(); ++end) {
            int left = start, right = end;
            bool isPalindrome = true;
            while (left < right) {
                if (s[left] != s[right]) {
                    isPalindrome = false;
                    break;
                }
                left++;
                right--;
            }
            if (isPalindrome) {
                currentPartition.push_back(s.substr(start, end - start + 1));
                backtrack(end + 1);
                currentPartition.pop_back();
            }
        }
    };
    backtrack(0);
    return result;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string S;
        
        cin>>S;

        Solution ob;
        vector<vector<string>> ptr = ob.allPalindromicPerms(S);
        
        for(int i=0; i<ptr.size(); i++)
        {
            for(int j=0; j<ptr[i].size(); j++)
            {
                cout<<ptr[i][j]<<" ";
            }
            cout<<endl;
        }
    }
    return 0;
}
// } Driver Code Ends
