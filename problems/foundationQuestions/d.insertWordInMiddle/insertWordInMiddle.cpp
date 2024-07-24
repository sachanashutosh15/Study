#include <iostream>

class Solution
{
public:
  static void insertWordMiddle(std::string &original, const std::string &toInsert)
  {
    // Write your code here
    std::string stringToInsert = " " + toInsert;
    int midIdx = original.length() / 2;
    original.insert(midIdx, stringToInsert);
    std::cout << original << std::endl;
  }
};

std::string get_sentence(std::string message)
{
  bool inputReceived = false;
  std::string input;
  do
  {
    std::cout << message << ": ";
    getline(std::cin, input);
    inputReceived = true;
  } while (!inputReceived);
  return input;
}

std::string get_string(std::string message)
{
  bool inputReceived = false;
  std::string input;
  do
  {
    std::cout << message << ": ";
    std::cin >> input;
    inputReceived = true;
  } while (!inputReceived);
  return input;
}

int main()
{
  std::string sentence = get_sentence("Provide a sentence");
  std::string word = get_string("Provide a word");
  Solution solution;
  solution.insertWordMiddle(sentence, word);
}