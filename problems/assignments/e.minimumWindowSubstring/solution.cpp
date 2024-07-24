#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  string minWindow(string s, string t) {
    unordered_map<char, int> t_charCountMap;
    int m = t.length();
    for (int i = 0; i < m; i++) {
      if (t_charCountMap.find(t[i]) != t_charCountMap.end()) {
        t_charCountMap[t[i]]++;
      } else {
        t_charCountMap[t[i]] = 1;
      }
    }
    int start = 0;
    int n = s.length();
    unordered_map<char, int> s_window;
    string result = "";
    int minLength = -1;
    for (int i = 0; i < n; i++) {
      if (s_window.find(s[i]) != s_window.end()) {
        s_window[s[i]]++;
      } else {
        s_window[s[i]] = 1;
      }
      while (isWindowComplete(s_window, t_charCountMap)) {
        cout << minLength << " " << i - start + 1 << endl;
        if (minLength == -1) {
          minLength = i - start + 1;
          result = s.substr(start, i + 1);
        } else if (i - start + 1 < minLength) {
          minLength = i - start + 1;
          result = s.substr(start, i - start + 1);
        }
        s_window[s[start]]--;
        if (s_window[s[start]] == 0) {
          s_window.erase(s[start]);
        }
        start++;
      }
    }
    return result;
  }
private:
  bool isWindowComplete(unordered_map<char, int> window, unordered_map<char, int> charCountMap) {
    for (auto &element: charCountMap) {
      if (window.find(element.first) == window.end() || window[element.first] < charCountMap[element.first]) {
        return false;
      }
    }
    return true;
  }
};

int main() {
  string s = "abc";
  string t = "b";
  Solution solution;
  string result = solution.minWindow(s, t);
  cout << result << endl;
}

/*
s = adobecodebanc
t = abc
{a: 1, b: 1, c: 1}
{a: 1, d: 1, o: 1, b: 1, e: 1, c: 1}
*/
