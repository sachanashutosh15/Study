#include <bits/stdc++.h>
using namespace std;

/*
 * price = {1, 3, 5, 8, 13, 21}
 * start = 0; end = 20;
 * mid = 10; isSweetnessPossible = false; end = 9;
 * mid = 0 + (9 - 0) / 2 = 4; isSweetnessPossible = true; start = 4;
 * mid = 4 + (9 - 5) / 2 = 6; isSweetnessPossible = true; start = 6;
 * mid = 6 + (9 - 6) / 2 = 7; isSweetnessPossible = true; start = 7;
 * mid = 7 + (9 - 7) / 2 = 8; isSweetnessPossible = true; start = 8;
 * mid = 8 + (9 - 8) / 2 = 8; isSweetnessPossible = true; start = 8;
 *
 * start = 0; end = 20;
 * mid = 10; isSweetnessPossible = false; end = 10;
 * mid = 0 + (10 - 0) / 2 = 5; isSweetnessPossible = true; start = 6;
 * mid = 6 + (10 - 6) / 2 = 8; isSweetnessPossible = true; start = 9;
 * mid = 9 + (10 - 9) / 2 = 9; isSweetnessPossible = false; end = 9;
 *
 * if (isSweetnessPossible) {
 *  start = mid + 1;
 * } else {
 *  end = mid;
 *  }
 */

class Solution {
public:
  int maximumSweetness(int n, vector<int> &price, int k) {
    sort(price.begin(), price.end());
    int start = 1;
    int end = price.back();
    int count = 0;
    while(end - start > 1) {
      count++;
      cout << start << " " << end << endl;
      int possibleSweetness = start + (end - start) / 2;
      bool isSweetnessPossible = isPossible(possibleSweetness, price, k);
      if (isSweetnessPossible) {
        start = possibleSweetness + 1;
      } else {
        end = possibleSweetness;
      }
    }
    return start - 1; 
  }
private:
  int isPossible(int possibleSweetness, vector<int> &price, int k) {
    cout << "checking for: " << possibleSweetness << endl;
    int n = price.size();
    int lastPrice = price[0];
    int count = 0;
    for (int i = 1; i < n; i++) {
      if (price[i] - lastPrice >= possibleSweetness) {
        count++;
        if (count == k - 1) {
          return true;
        }
        lastPrice = price[i];
      }
    }
    return false;
  }
};

int main() {
  vector<int> price = {3, 5, 1, 8, 21, 13};
  Solution solution;
  int n = price.size();
  int k = 3;
  int result = solution.maximumSweetness(n, price, k);
  cout << "result: " << result << endl;
}
