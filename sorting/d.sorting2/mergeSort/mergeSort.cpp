#include <bits/stdc++.h>
using namespace std;

int get_int(string message) {
  string input;
  while(true) {
    cout << message << ": ";
    getline(cin, input);
    if (input.empty()) {
      cout << "No input provided, please provide valid input" << endl;
      continue;
    }
    stringstream ss(input);
    int num;
    if (ss >> num && ss.eof()) {
      return num;
    } else {
      cout << "Invalid input. Please provide an integer." << endl;
    }
  }
  return 0;
}

void merge(int arr[], int start, int mid, int end) {
  int n1 = mid - start + 1;
  int n2 = end - mid;
  int* arr1 = new int[n1];
  int* arr2 = new int[n2];
  for (int i = 0; i < n1; i++) {
    arr1[i] = arr[i + start];
  }
  for (int i = 0; i < n2; i++) {
    arr2[i] = arr[mid + 1 + i];
  }
  int i = 0;
  int j = 0;
  int k = 0;
  while(i < n1 && j < n2) {
    if (arr1[i] < arr2[j]){
      arr[start + k] = arr1[i];
      i++;
    } else {
      arr[start + k] = arr2[j];
      j++;
    }
    k++;
  }
  while(i < n1) {
    arr[start + k] = arr1[i];
    i++;
    k++;
  }
  while(j < n2) {
    arr[start + k] = arr2[j];
    j++;
    k++;
  }
  delete[] arr1;
  delete[] arr2;
}

void mergeSort(int arr[], int start, int end) {
  if (start < end) {
    int mid = start + (end - start) / 2;
    mergeSort(arr, start, mid);
    mergeSort(arr, mid + 1, end);
    merge(arr, start, mid, end);
  }
}

void print_arr(int arr[], int n) {
  for (int i = 0; i < n; i++) {
    cout << arr[i] << " ";
  }
  cout << endl;
}

int main() {
  // int n = get_int("Provide the size of array");
  // int arr[n];
  // random_device rd;
  // mt19937 eng(rd());
  // uniform_int_distribution<int> distr(-n / 2, n / 2);
  // for (int i = 0; i < n; i++) {
  //   arr[i] = distr(eng);
  // }
  int arr[] = {11, 2, 6, 9, 20};
  int n = 5;
  print_arr(arr, n);
  auto start = chrono::high_resolution_clock::now();
  mergeSort(arr, 0, n - 1);
  auto end = chrono::high_resolution_clock::now();
  chrono::duration<double, milli> timeSpent = end - start;
  cout << "Time spent: " << timeSpent.count() << endl;
  print_arr(arr, n);
}
