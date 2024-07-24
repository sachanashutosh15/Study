#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int longestKSubstr(string s, int k) {
    cout << "s: " << s << endl;
    set<char> uniqueCharSet;
    int start = 0;
    int maxLength = 0;
    for (int i = 0; i < s.length(); i++) {
      uniqueCharSet.insert(s[i]);
      if (uniqueCharSet.size() > k) {
        while(s[start] == s[start + 1]) {
          start++;
        }
        uniqueCharSet.erase(s[start]);
        start++;
        i = start;
        cout << "start at: " << s[start] << endl;
      } else {
        maxLength = max(maxLength, i - start + 1);
      }
      for (auto element: uniqueCharSet) {
        cout << element << " ";
      }
      cout << endl;
    }
    return maxLength;
  }
};

int main() {
  string str = "aabacbebebe";
  int k = 3;
  Solution solution;
  int res = solution.longestKSubstr(str, k);
  cout << res << endl;
}

/*
 * maxLength = 0; start = 0; set = {};
 * i = 0; set = {a}; maxLength = 1;
 * i = 1; set = { a }; maxLength = 2;
 * i = 2; set = {a, b}; maxLength = 3;
 * i = 3; set = {a, b}; maxLength = 4;
 * i = 4; set = {a, b, c}; maxLength = 5;
 * i = 5; set = {a, b, c}; maxLength = 6;
 * i = 6; set = {a, b, c, e}; // set.size() > k
 *  
 */
