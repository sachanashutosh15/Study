#include <bits/stdc++.h>
using namespace std;

void print_matrix(vector<vector<int>> mat)
{
  int rowsCount = mat.size();
  int columnsCount = mat[0].size();
  for (int i = 0; i < rowsCount; i++)
  {
    string row = "";
    for (int j = 0; j < columnsCount; j++)
    {
      row += to_string(mat[i][j]) + " ";
    }
    cout << row << endl;
  }
}

class Solution
{
public:
  vector<vector<int>> matrixBlockSum(vector<vector<int>> &mat, int k)
  {
    cout << "k: " << k << endl;
    print_matrix(mat);
    int m = mat.size();
    int n = mat[0].size();
    vector<vector<int>> res(m);
    for (int i = 0; i < m; i++)
    {
      vector<int> resRow(n);
      for (int j = 0; j < n; j++)
      {
        resRow[j] = calcNewEle(mat, i, j, k);
      }
      res[i] = resRow;
    }
    return res;
  }

private:
  int calcNewEle(vector<vector<int>> mat, int i, int j, int k)
  {
    int m = mat.size();
    int n = mat[0].size();
    int i1 = max(0, i - k);
    int i2 = min(m - 1, i + k);
    int j1 = max(0, j - k);
    int j2 = min(n - 1, j + k);
    int res = 0;
    cout << "i1: " << i1 << " i2: " << i2 << " j1: " << j1 << " j2: " << j2 << endl;
    for (int i = i1; i <= i2; i++)
    {
      for (int j = j1; j <= j2; j++)
      {
        res += mat[i][j];
      }
    }
    return res;
  }
};

int get_int(string message)
{
  int input;
  bool isInputReceived = false;
  do
  {
    cout << message << ": ";
    cin >> input;
    if (cin.good())
    {
      isInputReceived = true;
      cin.clear();
      cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    else
    {
      cout << "Please provide valid input." << endl;
      cin.clear();
      cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
  } while (!isInputReceived);
  return input;
}

int main()
{
  int m = get_int("Enter number of rows");
  int n = get_int("Enter number of columns");
  vector<vector<int>> mat(m);
  for (int i = 0; i < m; i++)
  {
    cout << "Creating row " << i + 1 << endl;
    vector<int> row(n);
    for (int j = 0; j < n; j++)
    {
      row[j] = get_int("Enter the element " + to_string(j + 1));
    }
    mat[i] = row;
  }
  int k = get_int("Enter value of k");
  Solution solution;
  vector<vector<int>> result = solution.matrixBlockSum(mat, k);
  print_matrix(result);
}