#include <bits/stdc++.h>
using namespace std;

int main() {
  int M[][3] = {
    { 1, 2, 3 },
    { 4, 5, 6 },
    { 7, 8, 9 },
  };
  int prefixSumMatrix[3][3];
  memset(prefixSumMatrix, 0, sizeof(prefixSumMatrix));
  int n = sizeof(prefixSumMatrix) / sizeof(prefixSumMatrix[0]);
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      prefixSumMatrix[i][j] = M[i][j];
      if(i > 0)
        prefixSumMatrix[i][j] += prefixSumMatrix[i - 1][j];
      if(j > 0)
        prefixSumMatrix[i][j] += prefixSumMatrix[i][j - 1];
      if(i > 0 && j > 0)
        prefixSumMatrix[i][j] -= prefixSumMatrix[i - 1][j - 1];
    }
  }
  int k = 1;
  int result[3][3];
  memset(result, 0, sizeof(result));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      int r = min(i + k, n - 1);
      int c = min(j + k, n - 1);
      result[i][j] = prefixSumMatrix[r][c];
      if(i - k >= 1)
        result[i][j] -= prefixSumMatrix[i - k - 1][c];
      if(j - k >= 1)
        result[i][j] -= prefixSumMatrix[r][j - k - 1];
      if(i - k >= 1 && j - k >= 1)
        result[i][j] += prefixSumMatrix[i - k - 1][j - k - 1];
    }
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cout << result[i][j] << " ";
    }
    cout << endl;
  }
  return 0;
}
