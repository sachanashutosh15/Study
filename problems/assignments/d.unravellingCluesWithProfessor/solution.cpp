#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
  vector<int> findPatternIndices(string text, string pattern) {
  //Write your code here
  // ababcabab
  // ab
  // 01
    int n = text.length();
    int m = pattern.length();
    vector<int> result;
    for (int i = 0; i < n;) {
      cout << i << endl;
      int j = i;
      int k = 0;
      if (text[j] != pattern[k]) {
        i++;
        continue;
      }
      while (text[j] == pattern[k] && k < m) {
        j++; k++;
      }
      if (k == m) {
        result.push_back(i);
      }
      i++;
    }
    return result;
  }
};

int main() {
  string text = "ababcabab";
  string pattern = "ab";
  Solution solution;
  vector<int> result = solution.findPatternIndices(text, pattern);
  for (int i = 0; i < result.size(); i++) {
    cout << result[i] << " ";
  }
  cout << endl;
}
