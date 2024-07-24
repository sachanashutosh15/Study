#include <iostream>
#include <vector>
#include <limits>
#include <sstream>
using namespace std;

class Solution
{
public:
  vector<int> shuffle(vector<int> &nums, int n)
  {
    vector<int> result;
    for (int i = 0; i < n; i++)
    {
      result.push_back(nums[i]);
      result.push_back(nums[i + n]);
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

void print_vector(vector<int> vec)
{
  string result = "[ ";
  for (int i = 0; i < vec.size(); i++)
  {
    result += to_string(vec[i]) + ", ";
  }
  if (result.size() > 2)
  {
    result = result.substr(0, result.length() - 2);
  }
  result += " ]";
  cout << result << endl;
}

int main()
{
  int sizeOfInput;
  do
  {
    sizeOfInput = get_int("Provide the size of input");
    if (sizeOfInput % 2 == 0)
    {
      break;
    }
    cout << "Size of input can only be even integer." << endl;
  } while (sizeOfInput % 2 != 0);
  int n = sizeOfInput / 2;
  vector<int> nums;
  for (int i = 0; i < sizeOfInput; i++)
  {
    nums.push_back(get_int("Provide num " + to_string(i)));
  }
  Solution solution;
  vector<int> result = solution.shuffle(nums, n);
  print_vector(result);
}