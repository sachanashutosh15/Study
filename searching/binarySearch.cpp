#include <bits/stdc++.h>
using namespace std;

int binarySearch(int arr[], int size, int target);

int main() {
  int arr[] = { 2, 3, 1, 7, 5, 8, 6, 0};
  int n = sizeof(arr) / sizeof(arr[0]);
  int target = 14;
  sort(arr, arr + n);
  for (int i = 0; i < n; i++) {
    cout << arr[i] << " ";
  }
  cout << endl;
  int idx = binarySearch(arr, n, target);
  cout << "correct index of " << target << " is " << idx << endl;
}

int binarySearch(int arr[], int size, int target) {
  int start = 0;
  int end = size - 1;
  while (start <= end) {
    int mid = start + (end - start) / 2;
    cout << mid << endl;
    if (arr[mid] == target) {
      return mid;
    } else if (arr[mid] < target) {
      start = mid + 1;
    } else {
      end = mid - 1;
    }
  }
  return start;
}

