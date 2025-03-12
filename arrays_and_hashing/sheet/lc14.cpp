//Input: strs = ["flower","flow","flight"]
//Output: "fl"
#include <iostream>
#include <vector>
#include <string>

std::string longestCommonPrefix(std::vector<std::string>& strs){
    std::string res = "";
    int count = strs.size();
    for (int i = 0; i < count; i++){
        for(auto& s : strs){
            if((s[i] != strs[0][i]) || i == s.size()){
                return res;
            }
        }
        res += strs[0][i];
    }
    return res;
}

int main(){
    std::vector<std::string> strs = {"flower","flow","flight"};
    std::string res = longestCommonPrefix(strs);
    std::cout << res << "\n";
    return 0;
}
