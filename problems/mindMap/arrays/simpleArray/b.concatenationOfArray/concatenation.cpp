#include <iostream>
#include <vector>
#include <limits>
#include <sstream>
using namespace std;

class Solution
{
public:
  vector<int> getConcatenation(vector<int> &nums)
  {
    vector<int> result(nums);
    int length = nums.size();
    for (int i = 0; i < length; i++)
    {
      result.push_back(nums[i]);
    }
    return result;
  }
};

int get_int(string message)
{
  int input;
  bool inputReceived = false;
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
      cout << "Please provide valid input." << endl;
      cin.clear();
      cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
  } while (!inputReceived);
  return input;
}

void printVector(vector<int> vec)
{
  string result = "[ ";
  for (int i = 0; i < vec.size(); i++)
  {
    result += to_string(vec[i]) + ", ";
  }
  if (result.length() > 2)
  {
    result = result.substr(0, result.length() - 2);
  }
  result += " ]";
  cout << result << endl;
}

int main()
{
  int numOfElements = get_int("Enter the number of elements");
  vector<int> nums;
  for (int i = 0; i < numOfElements; i++)
  {
    nums.push_back(get_int("Enter element " + to_string(i)));
  }
  Solution solution;
  vector<int> result = solution.getConcatenation(nums);
  printVector(result);
}