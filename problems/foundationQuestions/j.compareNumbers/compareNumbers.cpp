#include <iostream>
#include <limits>
#include <sstream>
using namespace std;

class Solution
{
public:
  static void compareNumbers(int num1, int num2)
  {
    // Write your code here
    if (num2 > num1)
    {
      cout << "Second number is greater." << endl;
    }
    else if (num2 == num1)
    {
      cout << "Numbers are equal." << endl;
    }
    else
    {
      cout << "First number is greater." << endl;
    }
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
      cout << "Please provide a valid input." << endl;
      cin.clear();
      cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
  } while (!inputReceived);
  return input;
}

int main()
{
  int num1 = get_int("Provide the first number");
  int num2 = get_int("Provide the second number");
  Solution solution;
  solution.compareNumbers(num1, num2);
}