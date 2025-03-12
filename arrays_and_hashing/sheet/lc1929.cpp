// Input: nums = [1,2,1]
// Output: [1,2,1,1,2,1]
// Explanation: The array ans is formed as follows:
// - ans = [nums[0],nums[1],nums[2],nums[0],nums[1],nums[2]]
// - ans = [1,2,1,1,2,1]
#include <iostream>
#include <vector>
std::vector<int> getConcatenation(std::vector<int> &nums) {
    std::vector<int> ans;
    int size = nums.size() * 2;
    // taking the first half
    ans = nums;
    ans.resize(size);
    for (int i = nums.size(); i < size; i++) {
        ans[i] = nums[i - nums.size()];
    }
    return ans;
}
int main() {
    std::cout << "Enter the array size: " << std::endl;
    int size;
    std::cin >> size;

    std::vector<int> arr;
    std::cout << "Enter its elements: " << std::endl;
    for (int i = 0; i < size; i++) {
        int element;
        std::cin >> element;
        arr.push_back(element);  // Use push_back to add elements
    }
    std::vector<int> ans = getConcatenation(arr);
    std::cout << "Here is the result" << std::endl;
    for (auto n : ans) {
        std::cout << n << " ";
    }
    std::cout << std::endl;
    return 0;
}
