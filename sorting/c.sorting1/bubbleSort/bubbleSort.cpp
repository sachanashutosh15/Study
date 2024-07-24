#include <bits/stdc++.h>
using namespace std;

// https://github.com/I-am-sagar/problem-solving

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

void bubbleSort(int arr[], int n) {
  bool swapped = false;
  for (int i = 0; i < n; i++) {
    swapped = false;
    for (int j = 0; j < n - i - 1; j++) {
      if (arr[j + 1] < arr[j]) {
        int temp = arr[j];
        arr[j] = arr[j + 1];
        arr[j + 1] = temp;
        swapped = true;
      }
    } 
    if(!swapped) {
      break;
    }
  }
}

void print_array(int arr[], int n) {
  for (int i = 0; i < n; i++) {
    cout << arr[i] << " ";
  }
  cout << endl;
}

int main() {
  int n = get_int("Enter the size of the array");
  int arr[n]; 
  int lower_bound = - n / 2;
  int upper_bound = n / 2;
  random_device rd;
  mt19937 eng(rd());
  uniform_int_distribution<int> distr(lower_bound, upper_bound);
  for (int i = 0; i < n; i++) {
    arr[i] = distr(eng);
  }
  // print_array(arr, n);
  auto start = chrono::high_resolution_clock::now();
  cout << "Execution started" << endl;
  bubbleSort(arr, n);
  auto end = chrono::high_resolution_clock::now();
  chrono::duration<double, milli> duration = end - start;
  cout << "Execution time: " << duration.count() << " ms" << endl;
  // print_array(arr, n);
  return 0;
}
