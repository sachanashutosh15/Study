#include <iostream>
#include <sstream>
#include <limits>

class Solution
{
public:
  static void calculateDigitSums(int n)
  {
    int sumOfEvens = 0;
    int sumOfOdds = 0;
    while (n > 0)
    {
      int currDigit = n % 10;
      if (isEven(currDigit))
      {
        sumOfEvens += currDigit;
      }
      else
      {
        sumOfOdds += currDigit;
      }
      n = n / 10;
    }
    std::cout << sumOfEvens << " " << sumOfOdds << std::endl;
  }

private:
  static bool isEven(int num)
  {
    return (num % 2) == 0;
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
  int num = get_int("Provide a number");
  Solution solution;
  solution.calculateDigitSums(num);
}