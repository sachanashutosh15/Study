#include <iostream>
#include <limits>
#include <sstream>

class Solution
{
public:
  static void convertSeconds(int seconds)
  {
    const int secondsInHour = 60 * 60;
    const int secondsInMinute = 60;
    std::string HH;
    if (seconds / secondsInHour < 10)
    {
      HH = "0" + std::to_string(seconds / secondsInHour);
    }
    else
    {
      HH = std::to_string(seconds / secondsInHour);
    }
    seconds = seconds % secondsInHour;
    std::string mm;
    if (seconds / secondsInMinute < 10)
    {
      mm = "0" + std::to_string(seconds / secondsInMinute);
    }
    else
    {
      mm = std::to_string(seconds / secondsInMinute);
    }
    seconds = seconds % secondsInMinute;
    std::string SS;
    if (seconds < 10)
    {
      SS = "0" + std::to_string(seconds);
    }
    else
    {
      SS = std::to_string(seconds);
    }
    std::cout << HH << ":" << mm << ":" << SS << std::endl;
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
  int time = get_int("Provide the time in seconds");
  Solution solution;
  solution.convertSeconds(time);
}