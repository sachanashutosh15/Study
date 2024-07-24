#include <iostream>
#include <vector>
#include <limits>
#include <sstream>
using namespace std;

class Solution
{
public:
  // vector<int> buildArray(vector<int> &nums)
  // {
  //   vector<int> result;
  //   for (int i = 0; i < nums.size(); i++)
  //   {
  //     result.push_back(nums[nums[i]]);
  //   }
  //   return result;
  // }
  vector<int> buildArray(vector<int> &nums)
  {
    int length = nums.size();
    for (int i = 0; i < length; i++)
    {
      nums[i] += (nums[nums[i]] % length) * length;
    }
    for (int i = 0; i < length; i++)
    {
      nums[i] = nums[i] / length;
    }
    return nums;
  }
};

int get_int(string message)
{
  int input;
  bool inputReceived;
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
      cout << "Please provide a valid input." << endl;
      cin.clear();
      cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
  } while (!inputReceived);
  return input;
}

void printVector(vector<int> &vec)
{
  string result = "";
  for (int i = 0; i < vec.size(); i++)
  {
    result += to_string(vec[i]) + " ";
  }
  cout << result << endl;
}

int main()
{
  int elementsCount = get_int("Provide the number of elements");
  vector<int> nums;
  for (int i = 0; i < elementsCount; i++)
  {
    nums.push_back(get_int("Provide the element"));
  }
  Solution solution;
  vector<int> result = solution.buildArray(nums);
  printVector(result);
}
