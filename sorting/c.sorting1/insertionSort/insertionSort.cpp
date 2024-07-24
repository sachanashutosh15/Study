#include <bits/stdc++.h>
using namespace std;

/*
 * insertionSort
 * 5 1 4 2 6 3
 *
 */

int main() {
  int arr[] = { 10, 1, 4, 2, -4, 6, 3 };
  int n = sizeof(arr) / sizeof(arr[0]);
  for (int i = 1; i < n; i++) {
    int j = i - 1;
    int currNum = arr[i];
    while(j >= 0 && arr[j] > currNum) {
      arr[j + 1] = arr[j];
      j--;
    }
    arr[j + 1] = currNum;
  }
  for (int i = 0; i < n; i++) {
    cout << arr[i] << " ";
  }
  cout << endl;
}
