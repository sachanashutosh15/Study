#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  string minWindow(string s, string t) {
    unordered_map<char, int> charCountMap;
    int m = t.length();
    for (int i = 0; i < m; i++) {
      if (!charCountMap[t[i]]) {
        charCountMap[t[i]] = 1;
      } else {
        charCountMap[t[i]]++;
      }
    }
    int requiredChars = m;
    int n = s.length();
    int start = 0;
    int minLength = INT_MAX;
    int minLeft = 0;
    for (int i = 0; i < n; i++) {
      if (charCountMap[s[i]] > 0) {
        requiredChars--;
      } 
      charCountMap[s[i]]--;
      while (requiredChars == 0) {
        if (i - start + 1 < minLength) {
          minLength = i - start + 1;
          minLeft = start;
        }
        charCountMap[s[start]]++;
        if (charCountMap[s[start]] > 0) {
          requiredChars++;
        }
        start++;
      }
    }
    return minLength == INT_MAX ? "" : s.substr(minLeft, minLength);
  }
};

int main() {
  string s = "bba";
  string t = "ab";
  Solution solution;
  string result = solution.minWindow(s, t);
  cout << "result: " << result << endl;
}

/*
 * bba {a: 1, b: 1}
 * requiredChars = 2;
 * i = 0; {a: 1, b: 0} requiredChars = 1;
 * i = 1: {a: 1, b: 0} requiredChars = 1;
 * i = 2: {a: 0, b: 0} requiredChars = 0;
 */
