#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int maximumGap(vector<int>& nums) {
    int min = *min_element(nums.begin(), nums.end());
    int max = *max_element(nums.begin(), nums.end());
    int range = max - min;
    int n = nums.size();
    int bucketSize = std::max(1, range / (n - 1));
    int bucketCount = range / bucketSize + 1;
    vector<pair<int, int>> sortedBuckets(bucketCount, {-1, -1});
    for (int i = 0; i < n; i++) {
      int idx = (nums[i] - min) / bucketSize;
      pair<int, int> currPair = sortedBuckets[idx];
      currPair.first = idx;
      currPair.second = nums[i];
    }
    int maxAbsDiff = 0;
    int lastVal = min;
    for (auto pair: sortedBuckets) {
      if (pair.first != -1) {
        maxAbsDiff = std::max(maxAbsDiff, pair.second - lastVal);
        lastVal = pair.second;
      }
    }
    return maxAbsDiff;
  }
};

int main() {
    vector<int> nums = {3, 6, 9, 1};
    Solution solution;
    int res = solution.maximumGap(&nums);
    cout << res << endl;
    return 0;
}
