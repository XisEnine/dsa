// Input: nums = [3,2,2,3], val = 3
// Output: 2, nums = [2,2,_,_]
// Explanation: Your function should return k = 2, with the first two elements of nums being 2.
// It does not matter what you leave beyond the returned k (hence they are underscores).
#include <iostream>
#include <vector>

int removeELement(std::vector<int>& nums,int val){
    int index = 0;
    for(int i = 0; i < nums.size(); i++){
        if(nums[i] != val){
            nums[index] = nums[i];
            index += 1;
        }
    }
    return index;
}

int main(){
    std::vector<int> nums = {3,2,2,3};
    int element = 3;
    int index = removeELement(nums, element);
    std::cout << index << std::endl;
}
