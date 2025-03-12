// Input: nums = [1,2,3,1]
//
// Output: true
//
// Explanation:
//
// The element 1 occurs at the indices 0 and 3.
#include <iostream>
#include <vector>
#include <unordered_set>
// bool containsDuplicate(std::vector<int>& nums){
//    unordered_set<int>st;
//     for(auto n : nums){
//         if(st.find(n) != st.end()){
//             return true;
//         } else {
//             st.insert(n);    
//         }
//     }
//     return false;
// }
bool containsDuplicate(std::vector<int>& nums){
    std::unordered_set<int>st;
    for(auto n : nums){
        if(st.find(n) != st.end()){
            return true;
        } else {
            st.insert(n);    
        }
    }
    return false;
}
int main(){
    std::vector<int> nums = {1,2,3};
    bool res = containsDuplicate(nums);
    std::cout << "Result : " << res << std::endl;
    return 0;
}
