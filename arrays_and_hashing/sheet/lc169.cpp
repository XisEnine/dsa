// Input: nums = [2,2,1,1,1,2,2]
// Output: 2
#include <iostream>
#include <vector>

int majorityElement(std::vector<int> &nums) {
    int cnt = 1;
    int ele = nums[0];
    for (int i = 1; i < nums.size(); i++) {
        if (nums[i] == ele) {
            cnt += 1;
        } else {
            cnt -= 1;
            if (cnt == 0) {
                cnt = 1;
                ele = nums[i];
            }
        }
    }
    return ele;
}
int main() {
    std::vector<int> nums = {2, 2, 1, 1, 1, 2, 2};
    int n = nums.size();
    int res = majorityElement(nums);
    std::cout << res << "\n";
    return 0;
}
