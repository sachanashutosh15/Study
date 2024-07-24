#include <iostream>
#include <limits>
#include <sstream>
using namespace std;

class Solution
{
public:
  static void calculateAverage(char name, int M, int S, int E, int H, int C)
  {
    int avgMarks = (M + S + E + H + C) / 5;
    cout << name << endl;
    cout << avgMarks << endl;
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
      cout << "Please provide a valid input." << endl;
      cin.clear();
      cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
  } while (!inputReceived);
  return input;
}

int main()
{
  char studentName = 'A';
  int M = get_int("Enter the marks of Maths");
  int S = get_int("Enter the marks of Maths");
  int E = get_int("Enter the marks of Maths");
  int H = get_int("Enter the marks of Maths");
  int C = get_int("Enter the marks of Maths");
  Solution solution;
  solution.calculateAverage(studentName, M, S, E, H, C);
}