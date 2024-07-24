#include <iostream>
#include <limits>
#include <sstream>
using namespace std;

class Solution
{
public:
  static void printDivisibleNumbers(int start, int end, int num1, int num2)
  {
    string result = "";
    int gcd = calcGCD(num1, num2);
    int divisor = num1 * num2 / gcd;
    int firstDivisibleNum = start;
    for (int i = start; i <= end; i++)
    {
      if (i % divisor == 0)
      {
        firstDivisibleNum = i;
        break;
      }
    }
    for (int i = firstDivisibleNum; i <= end; i += divisor)
    {
      result += to_string(i) + " ";
    }
    cout << result << endl;
  }

private:
  static int calcGCD(int a, int b)
  {
    if (b == 0)
    {
      return a;
    }
    return calcGCD(b, a % b);
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
  int start = get_int("Provide start value");
  int end = get_int("Provide end value");
  int num1 = get_int("Provide num1 value");
  int num2 = get_int("Provide num2 value");
  Solution solution;
  solution.printDivisibleNumbers(start, end, num1, num2);
}
