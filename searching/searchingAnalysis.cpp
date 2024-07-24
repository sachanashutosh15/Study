#include <bits/stdc++.h>
using namespace std;

int main() {
  int start = 1;
  int end = 26;
  int count = 0;
  // cout << "Taking least integer: " << endl;
  // while(start <= end) {
  //   int mid = start + (end - start + 1) / 2;
  //   cout << start << " " << mid << " " << end << endl;
  //   if (false) {
  //     start = mid;
  //   } else {
  //     end = mid - 1;
  //   }
  // }

  // count = 0;
  // start = 1;
  // end = 25;
  cout << "Taking integer division: " << endl;
  while(start < end) {
    int mid = start + (end - start) / 2;
    cout << start << " " << mid << " " << end << endl;
    if (false) {
      start = mid + 1;
    } else {
      end = mid;
    }
  }
}
