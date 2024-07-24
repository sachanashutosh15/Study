#include <iostream>
#include <limits>
#include <sstream>

class Solution
{
public:
  static std::string toLowerCase(const std::string &str)
  {
    std::string result = "";
    for (int i = 0; i < str.length(); i++)
    {
      int asciiVal = (int)str[i];
      if (asciiVal >= 65 && asciiVal <= 90)
      {
        char lowerCaseChar = (char)(asciiVal + 32);
        result += lowerCaseChar;
      }
      else
      {
        result += str[i];
      }
    }
    return result;
  }
};

std::string get_string(std::string message)
{
  std::string input;
  bool isInputReceived = false;
  do
  {
    std::cout << message << ": ";
    std::cin >> input;
    if (std::cin.good())
    {
      isInputReceived = true;
    }
    else
    {
      std::cout << "Please provide a valid input." << std::endl;
      std::cin.clear();
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
  } while (!isInputReceived);
  return input;
}

int main()
{
  std::string input = get_string("Provide the string");
  Solution solution;
  std::string result = solution.toLowerCase(input);
  std::cout << "Result: " << result << std::endl;
}