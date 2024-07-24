#include <iostream>
using namespace std;

class Solution
{
public:
  static string reverseString(string s)
  {
    string result = "";
    for (int i = s.length() - 1; i >= 0; i--)
    {
      result += s[i];
    }
    return result;
  }
};

string get_sentence(string message)
{
  string input;
  cout << message << ": ";
  getline(cin, input);
  return input;
}

int main()
{
  string input = get_sentence("Provide the string to be reversed");
  Solution solution;
  string result = solution.reverseString(input);
  cout << result << endl;
}