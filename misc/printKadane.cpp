#include <climits>
#include <iostream>
#include <vector>
using namespace std;

void printKadane(vector<int> nums) {
  int sum = 0, max = INT_MIN;
  int start = 0;
  int begin = 0, end = 0;
  for (int i = 0; i < nums.size(); i++) {
    sum += nums[i];
    if (sum > max) {
      max = sum;
      end = i;
      begin = start;
    }
    if (sum < 0) {
      sum = 0;
      start = i + 1;
    }
  }
  for (auto it = nums.begin() + begin; it <= nums.begin() + end; ++it) {
    cout << *it << " ";
  }
  cout << "\n";
}

int main() { printKadane({-2, 1, -3, 4, -1, 2, 1, -7, 4}); }
