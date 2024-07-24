#include <iostream>
#include <limits>
#include <sstream>
using namespace std;

class Solution
{
public:
  static int sumOfDigits(int N)
  {
    int result = 0;
    while (N > 0)
    {
      result += N % 10;
      N = N / 10;
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
  int num = get_int("Provide a number");
  Solution solution;
  int result = solution.sumOfDigits(num);
  cout << "Sum of Digits: " << result << endl;
}