class Solution {
public:
    string reorganizeString(string s) {
    const int n = s.length();
    vector<int> count(128);
    char maxChar = 'a' - 1;
    for (const char c : s) ++count[c];
    for (char c = 'a'; c <= 'z'; ++c)
      if (count[c] > count[maxChar]) maxChar = c;
    if (count[maxChar] > (n + 1) / 2) return "";
    string ans(n, ' ');
    int i = 0; 
    auto fillIn = [&](char c) {
      ans[i] = c;
      i += 2;
      if (i >= n)   i = 1;
    };
    while (count[maxChar]-- > 0) fillIn(maxChar);
    for (char c = 'a'; c <= 'z'; ++c)
      while (count[c] > 0) {
        --count[c];
        fillIn(c);
      }
    return ans;
    }
};