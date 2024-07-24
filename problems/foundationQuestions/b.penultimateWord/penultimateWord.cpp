#include <iostream>
#include <limits>
#include <sstream>
using namespace std;

// this is a test sentence.

class Solution
{
public:
  static string findPenultimateWord(const string &sentence)
  {
    int startIdx;
    int endIdx;
    int spaceCount = 0;
    for (int i = sentence.length() - 1; i >= 0; i--)
    {
      if (sentence[i] == ' ')
      {
        spaceCount++;
        if (spaceCount == 1)
        {
          endIdx = i;
        }
        if (spaceCount == 2 || i == 0)
        {
          startIdx = i;
          break;
        }
      }
    }
    return sentence.substr(startIdx + 1, endIdx - startIdx - 1);
  }
};

string get_sentence(string message)
{
  string input;
  bool inputReceived = false;
  do
  {
    cout << message << ": ";
    getline(cin, input);
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
  string input = get_sentence("Provide a sentence");
  Solution solution;
  string result = solution.findPenultimateWord(input);
  cout << "Result: " << result << result.length() << endl;
}
