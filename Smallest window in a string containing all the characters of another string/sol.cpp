//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends

#define NO_OF_CHARS 256
class Solution
{
    public:
    //Function to find the smallest window in the string s consisting
    //of all the characters of string p.
    string smallestWindow (string S, string T)
    {
        // Your code here
    int Slen = S.length();
    int Tlen = T.length();
    if (Slen < Tlen)
    {
        return "-1";
    }
    int S_count[NO_OF_CHARS] = {0};
    int T_count[NO_OF_CHARS] = {0};
    for (int i = 0; i < Tlen; i++)
        T_count[T[i]]++;
    int start = 0, start_index = -1, min_len = INT_MAX;
    int count = 0;  
    for (int i = 0; i < Slen ; i++)
    {
        S_count[S[i]]++;
        if (T_count[S[i]] != 0 && S_count[S[i]] <= T_count[S[i]] )
            count++;
        if (count == Tlen)
        {
            while ( S_count[S[start]] > T_count[S[start]] || T_count[S[start]] == 0)
            {
                if (S_count[S[start]] > T_count[S[start]])
                    S_count[S[start]]--;
                start++;
            }
            int len_window = i - start + 1;
            if (min_len > len_window)
            {
                min_len = len_window;
                start_index = start;
            }
        }
    }
    if (start_index == -1)
    {
       return "-1";
     
    }
    return S.substr(start_index, min_len);
    }
};


//{ Driver Code Starts.
int main()
 {
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        string pat;
        cin>>pat;
        Solution obj;
        cout<<obj.smallestWindow(s, pat)<<endl;
        
    }
	return 0;
}
// } Driver Code Ends
