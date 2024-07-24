#include <iostream>
#include <vector>
#include <limits>
#include <sstream>

class Solution
{
public:
  static std::vector<std::string> findLongestWords(const std::vector<std::string> &words)
  {
    std::vector<std::string> result;
    int size_of_longest_word = 0;
    for (int i = 0; i < words.size(); i++)
    {
      if (words[i].length() > size_of_longest_word)
      {
        size_of_longest_word = words[i].length();
        result.clear();
        result.push_back(words[i]);
      }
      else if (words[i].length() == size_of_longest_word)
      {
        result.push_back(words[i]);
      }
    }
    return result;
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

std::string get_string(std::string message)
{
  std::cout << message << ": ";
  std::string input;
  std::cin >> input;
  return input;
}

int main()
{
  std::vector<std::string> words;
  int wordsCount = get_int("Enter the number of words");
  for (int i = 0; i < wordsCount; i++)
  {
    std::string message = "Enter word " + std::to_string(i);
    std::string word = get_string(message);
    words.push_back(word);
  }
  Solution solution;
  std::vector<std::string> result = solution.findLongestWords(words);
  for (int i = 0; i < result.size(); i++)
  {
    std::cout << result[i] << std::endl;
  }
}