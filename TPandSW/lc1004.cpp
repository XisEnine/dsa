#include <iostream>
#include <vector>

using namespace std;

// Brute -> TC -> O(N^2)
/*int longestOnes(vector<int> &nums, int k) {*/
/*  int maxLen = INT_MIN;*/
/*  int n = nums.size();*/
/*  for (int i = 0; i < n; i++) {*/
/*    int zeros = 0;*/
/*    for (int j = i; j < n; j++) {*/
/*      if (nums[j] == 0)*/
/*        zeros++;*/
/*      if (zeros <= k) {*/
/*        int len = j - i + 1;*/
/*        maxLen = max(maxLen, len);*/
/*      } else {*/
/*        break;*/
/*      }*/
/*    }*/
/*  }*/
/*  return maxLen;*/
/*}*/

// using sliding window
int longestOnes(vector<int> &nums, int k) {
  int left = 0, right = 0;
  int n = nums.size();
  int checkZero = 0;
  int best = 0;
  while (right < n) {
    if (nums[right] == 0)
      checkZero++;
	//shrinking the window size until we get the range of 0's as K
    while (checkZero > k) {
      if (nums[left] == 0)
        checkZero--;
      left++;
    }
    best = max(best, right - left + 1);
    right++;
  }
  return best;
}

int main(void) {
  vector<int> nums = {0, 0, 1, 1, 0, 0, 1, 1, 1, 0, 1, 1, 0, 0, 0, 1, 1, 1, 1};
  int k = 3;
  int res = longestOnes(nums, k);
  cout << res << endl;
  return 0;
}
