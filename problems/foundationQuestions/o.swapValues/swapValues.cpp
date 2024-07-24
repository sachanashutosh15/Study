#include <iostream>
#include <limits>
#include <sstream>
using namespace std;

class Solution
{
public:
  static void swap(int a, int b)
  {
    int temp = a;
    a = b;
    b = temp;
    cout << a << " " << b << endl;
  }
};

int get_int(string message)
{
  int input;
  bool inputReceived;
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
  int a = get_int("Provide value of a");
  int b = get_int("Provide value of b");
  Solution solution;
  solution.swap(a, b);
}