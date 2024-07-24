#include <iostream>
#include <limits>
#include <sstream>
using namespace std;

class Solution
{
public:
  static int countDivisible(int start, int end, int divisor)
  {
    int firstDivisibleNum = start;
    for (int i = start; i <= end; i++)
    {
      if (i % divisor == 0)
      {
        firstDivisibleNum = i;
        break;
      }
    }
    int result = ((end - firstDivisibleNum) / divisor) + 1;
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
  int startNum = get_int("Enter start Number");
  int endNum = get_int("Enter end Number");
  int divisor = get_int("Enter the divisor");
  Solution solution;
  int result = solution.countDivisible(startNum, endNum, divisor);
  cout << "Result: " << result << endl;
}