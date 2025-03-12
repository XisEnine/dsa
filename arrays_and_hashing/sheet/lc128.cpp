// Input: nums = [100,4,200,1,3,2]
// Output: 4
// Explanation: The longest consecutive elements sequence is [1, 2, 3, 4]. Therefore its length is 4.
#include <algorithm>
#include <iostream>
#include <vector>
#include <unordered_set>

int longestConsecutive(std::vector<int> &nums){
    int current_cnt = 0;
    int longest_cnt = 0;
    std::unordered_set<int> st;
    //pre storing the values to later search in set
    for(auto it : nums){
        st.insert(it);
    }
    //now we will search for each consecutive value which was hashed into the set
    for(auto i : st){
        //checking for the values
        if(st.find(i) != st.end()){
            int nextValue = i + 1;
            current_cnt = 1;
            while(st.find(nextValue) != st.end()){
                nextValue += 1;
                current_cnt += 1;
            }
            longest_cnt = std::max(current_cnt,longest_cnt);
        }
    }
    return longest_cnt;
}

int main(){
    std::vector<int> nums = {100,4,200,1,3,2};
    int res = longestConsecutive(nums);
    std::cout << res << std::endl;
    return 0;
}
