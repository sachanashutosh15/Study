#include <bits/stdc++.h>
using namespace std;

int get_int(string message)
{
  string input;
  while (true)
  {
    cout << message << ": ";
    getline(cin, input);
    if (input.empty())
    {
      cout << "No input received. Please provide input." << endl;
      continue;
    }
    stringstream strStrm(input);
    int num;
    if (strStrm >> num && strStrm.eof())
    {
      return num;
    }
    else
    {
      cout << "Invalid input. Please provide an integer." << endl;
    }
  }
}

int *merge(int arr1[], int n1, int arr2[], int n2)
{
  int *res = new int[n1 + n2];
  int resIdx = 0;
  int i1 = 0;
  int i2 = 0;
  while (i1 < n1 && i2 < n2)
  {
    if (arr1[i1] < arr2[i2])
    {
      res[resIdx] = arr1[i1];
      i1++;
      resIdx++;
    }
    else
    {
      res[resIdx] = arr2[i2];
      i2++;
      resIdx++;
    }
  }
  while (i1 < n1)
  {
    res[resIdx] = arr1[i1];
    i1++;
    resIdx++;
  }
  while (i2 < n2)
  {
    res[resIdx] = arr2[i2];
    i2++;
    resIdx++;
  }
  return res;
}

void print_arr(int arr[], int n)
{
  for (int i = 0; i < n; i++)
  {
    cout << arr[i] << " ";
  }
  cout << endl;
}

int main()
{
  int n1 = get_int("Provide the size of arr1");
  int *arr1 = new int[n1];
  for (int i = 0; i < n1; i++)
  {
    arr1[i] = get_int("Enter element " + to_string(i) + ": ");
  }
  int n2 = get_int("Provide the size of arr2");
  int *arr2 = new int[n2];
  for (int i = 0; i < n2; i++)
  {
    arr2[i] = get_int("Enter element " + to_string(i) + ": ");
  }
  int *mergedArr = merge(arr1, n1, arr2, n2);
  print_arr(mergedArr, n1 + n2);
  delete[] arr1;
  delete[] arr2;
  delete[] mergedArr;
  return 0;
}
