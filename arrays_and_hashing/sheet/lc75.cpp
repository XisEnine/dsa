// Input: nums = [2,0,2,1,1,0]
// Output: [0,0,1,1,2,2]
#include <iostream>
#include <utility>
#include <vector>
#define fori(n) for (int i = 0; i < n; i++)
// void sortColors(std::vector<int>& nums){
//     int zeroCnt = 0, oneCnt = 0,twoCnt = 0;
//     //counting each number
//     int n = nums.size();
//     fori(n){
//         if(nums[i] == 0){
//             zeroCnt += 1;
//         }else if(nums[i] == 1){
//             oneCnt += 1;
//         }else{
//             twoCnt += 1;
//         }
//     }
//         for (int i = 0; i < zeroCnt; i++) {
//         nums[i] = 0;
//     }
//     for (int i = zeroCnt; i < zeroCnt + oneCnt; i++) {
//         nums[i] = 1;
//     }
//     for (int i = zeroCnt + oneCnt; i < nums.size(); i++) {
//         nums[i] = 2;
//     }
// }
void sortColors(std::vector<int>& nums) {
    int l = 0, m = 0, h = nums.size() - 1;

    // Traverse through the array using the middle pointer
    while (m <= h) {
        if (nums[m] == 0) {
            std::swap(nums[l], nums[m]);
            l++;
            m++;
        } else if (nums[m] == 1) {
            m++;
        } else { // nums[m] == 2
            std::swap(nums[m], nums[h]);
            h--;
        }
    }
}

int main() {
    std::vector<int> nums = {0, 0, 1, 1, 2, 2};
    sortColors(nums);
    fori(nums.size()) { std::cout << nums[i] << " "; }
    std::cout << std::endl;
    return 0;
}
