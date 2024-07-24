#include <iostream>
#include <limits>
#include <sstream>
using namespace std;

class Solution
{
public:
  static long long power(int x, int n)
  {
    long long result = 1;
    while (n > 0)
    {
      result *= x;
      n--;
    }
    return result;
  }
};

int get_int(string message)
{
  int input;
  bool inputReceived = false;
  do
  {
    cout << message << ": ";
    cin >> input;
    if (cin.good())
    {
      inputReceived = true;
    }
    else
    {
      cout << "Please provide valid input." << endl;
      cin.clear();
      cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
  } while (!inputReceived);
  return input;
}

int main()
{
  int x = get_int("Provide value of x");
  int n = get_int("Provide value of n");
  Solution solution;
  long long result = solution.power(x, n);
  cout << "Result: " << result << endl;
  cout << numeric_limits<int>::min() << endl;
  cout << numeric_limits<int>::max() << endl;
}