#include <iostream>
using namespace std;

class Solution
{
public:
  static void analyzeString(string input)
  {
    int letterCount = 0;
    int spaceCount = 0;
    int spCharCount = 0;
    int numberCount = 0;
    for (int i = 0; i < input.length(); i++)
    {
      int currCharValue = input[i];
      if ((currCharValue >= 97 && currCharValue <= 122) || (currCharValue >= 65 && currCharValue <= 90))
      {
        letterCount++;
      }
      else if (currCharValue >= 48 && currCharValue <= 57)
      {
        numberCount++;
      }
      else if (currCharValue == 32)
      {
        spaceCount++;
      }
      else
      {
        spCharCount++;
      }
    }
    cout << letterCount << " " << spaceCount << " " << numberCount << " " << spCharCount << endl;
  }
};

string get_sentence(string message)
{
  cout << message << ": ";
  string input;
  getline(cin, input);
  return input;
}

int main()
{
  std::string input = get_sentence("Provide the string to analyze");
  Solution solution;
  solution.analyzeString(input);
}