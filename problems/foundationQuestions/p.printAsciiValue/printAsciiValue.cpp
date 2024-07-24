#include <iostream>
#include <limits>
#include <sstream>
using namespace std;

class Solution
{
public:
  static void printAsciiValue(char character)
  {
    int asciiValue = (int)character;
    cout << asciiValue << endl;
  }
};

char get_char(string message)
{
  char input;
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
      cin.clear();
      cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
  } while (!inputReceived);
  return input;
}

int main()
{
  char input = get_char("Please provide a char");
  Solution solution;
  solution.printAsciiValue(input);
}