#include <iostream>
#include <limits>
#include <sstream>

class Solution
{
public:
  static bool checkCommonDigit(int num1, int num2)
  {
    std::string num1Str = std::to_string(num1);
    std::string num2Str = std::to_string(num2);
    for (int i = 0; i < num1Str.length(); i++)
    {
      for (int j = 0; j < num2Str.length(); j++)
      {
        if (num1Str[i] == num2Str[j])
        {
          return true;
        }
      }
    }
    return false;
  }
};

int get_int(std::string message)
{
  int input;
  bool inputReceived = false;
  do
  {
    std::cout << message << ": ";
    std::cin >> input;
    if (std::cin.good())
    {
      inputReceived = true;
    }
    else
    {
      std::cout << "Please provide valid input." << std::endl;
      std::cin.clear();
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
  } while (!inputReceived);
  return input;
}

int main()
{
  int num1 = get_int("Enter first Number");
  int num2 = get_int("Enter second Number");
  Solution solution;
  bool result = solution.checkCommonDigit(num1, num2);
  std::cout << "Result: " << result << std::endl;
  return 0;
}
