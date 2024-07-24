#include <iostream>
#include <limits>
#include <sstream>
#include <cmath>
using namespace std;

class Solution
{
public:
  static void printFactors(int n)
  {
    // Write your code here
    string result = "";
    int limit = (n / 2) + 1;
    for (int i = 2; i < limit; i++)
    {
      if (n % i == 0)
      {
        result += to_string(i) + " ";
      }
    }
    if (result == "")
    {
      cout << "-1" << endl;
    }
    else
    {
      cout << trim(result) << endl;
    }
  }

private:
  static string trim(string str)
  {
    int startIdx = str.find_first_not_of(' ');
    int lastIdx = str.find_last_not_of(' ');
    return str.substr(startIdx, lastIdx - startIdx + 1);
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
  int num = get_int("Provide a number");
  Solution solution;
  solution.printFactors(num);
}