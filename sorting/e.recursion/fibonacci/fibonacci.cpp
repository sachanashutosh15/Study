#include <bits/stdc++.h>
using namespace std;

int fibonacci(int n) {
  if (n == 1) {
    return 0;
  }
  if (n == 2) {
    return 1;
  }
  return fibonacci(n - 1) + fibonacci(n - 2);
}

int main() {
  int res = fibonacci(8); 
  cout << res << endl;
}

// 0 1 1 2 3 5 8 ...
