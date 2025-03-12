// Input: nums = [2,7,11,15], target = 9
// Output: [0,1]
// Explanation: Because nums[0] + nums[1] == 9, we return [0, 1].
#include <vector>
#include <iostream>
#include <unordered_map>
std::vector<int> twoSum(std::vector<int> &nums, int target){
    std::unordered_map<int, int> mpp;
    //pre-hashing all values
    for(int i = 0; i < nums.size(); i++){
        int rem = target - nums[i];
        if(mpp.find(rem) != mpp.end()){
            return {i,mpp[rem]};
        }
        mpp[nums[i]] = i;
    }
    return {-1,-1};
}

int main(){
    std::vector<int> nums = {2,7,11,15};
    int target = 9;
    std::vector<int> result = twoSum(nums,target);
    for(auto n : result){
        std::cout << n << " ";
    }
    std::cout<<std::endl;
    return 0;
}
