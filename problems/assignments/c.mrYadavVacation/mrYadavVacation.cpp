#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    void solve(int weather[], int n, int k, int t) {
      int startIdx = 0;
      int consecutiveDays = 0;
      int i = 0;
      int count = 0;
      while(i < n) {
        if (weather[i] <= t) {
          consecutiveDays++;
        } else {
          consecutiveDays = 0;
          startIdx = i + 1;
        }
        if (consecutiveDays >= k) {
          count += i - startIdx - k + 2;
        }
        i++;
      }
      cout << "count: " << count << endl;
    }
};

int main() {
  int weather[] = {-5, 0, 10, -10};
  int n = sizeof(weather) / sizeof(weather[0]);
  int k = 1;
  int t = 15;
  Solution solution;
  solution.solve(weather, n, k, t);
}
