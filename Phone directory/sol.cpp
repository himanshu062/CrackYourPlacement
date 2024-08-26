//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    vector<vector<string>> displayContacts(int n, string contact[], string s)
    {
        // code here
        sort(contact,contact+n);

        set<string> st;

        for(int i=0;i<n;i++) st.insert(contact[i]);

        vector<vector<string>> ans;

           for(int j=0;j<s.size();j++){

                vector<string> temp;

                for(auto it:st){

                    if(s.substr(0,j+1)==it.substr(0,j+1)) temp.push_back(it);

                }

                if(temp.size()==0) temp.push_back("0");

                ans.push_back(temp);

           }
           return ans;
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        string contact[n], s;
        for(int i = 0;i < n;i++)
            cin>>contact[i];
        cin>>s;
        
        Solution ob;
        vector<vector<string>> ans = ob.displayContacts(n, contact, s);
        for(int i = 0;i < ans.size();i++){
            for(auto u: ans[i])
                cout<<u<<" ";
            cout<<"\n";
        }
    }
    return 0;
}
// } Driver Code Ends
