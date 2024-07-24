#include <bits/stdc++.h>
using namespace std;

int get_int(string message) {
  string input;
  while(true) {
    cout << message << ": ";
    getline(cin, input);
    if (input.empty()) {
      cout << "No input provided. Please provide some valid input." << endl;
      continue;
    }
    stringstream ss(input);
    int num;
    if (ss >> num && ss.eof()) {
      return num;
    } else {
      cout << "Invalid input. Please provide an integer!!" << endl;
    }
  }
}

void selectionSort(int arr[], int n) {
  int minIdx = 0;
  for (int i = 0; i < n; i++) {
    for (int j = i; j < n; j++) {
      if(arr[j] < arr[minIdx]) {
        minIdx = j;
      }
    }
    int temp = arr[i];
    arr[i] = arr[minIdx];
    arr[minIdx] = temp;
  }
}

void print_arr(int arr[], int n) {
  for (int i = 0; i < n; i++) {
    cout << arr[i] << " ";
  }
  cout << endl;
}

int main() {
  int n = get_int("Enter the size of the array");
  random_device rd;
  mt19937 eng(rd());
  uniform_int_distribution<> distr(-n/2, n/2);
  int arr[n];
  for (int i = 0; i < n; i++) {
    arr[i] = distr(eng);
  }
  auto start = chrono::high_resolution_clock::now();
  // print_arr(arr, n);
  selectionSort(arr, n);
  auto end = chrono::high_resolution_clock::now();
  chrono::duration<double, milli> duration = end - start;
  cout << "Execution time: " << duration.count() << " ms" << endl;
  // print_arr(arr, n);
  return 0;
}
