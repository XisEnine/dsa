// Input: strs = ["eat","tea","tan","ate","nat","bat"]
//
// Output: [["bat"],["nat","tan"],["ate","eat","tea"]]
//
// Explanation:
//
// There is no string in strs that can be rearranged to form "bat".
// The strings "nat" and "tan" are anagrams as they can be rearranged to form
// each other. The strings "ate", "eat", and "tea" are anagrams as they can be
// rearranged to form each other.
#include <algorithm>
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
std::vector<std::vector<std::string>> groupAnagrams(
    std::vector<std::string> strs) {
    std::vector<std::vector<std::string>> ans;
    std::unordered_map<std::string, std::vector<std::string>> mpp;
    for (const std::string &word : strs) {
        // copied the word here
        std::string sortedWord = word;
        // here after sorting the word will be pushed to key if it is its
        // anagram else it will create a new key.
        std::sort(sortedWord.begin(), sortedWord.end());
        mpp[sortedWord].push_back(word);
    }
    // collecting the result back into the result vector
    for (auto &group : mpp) {
        ans.push_back(group.second);
    }
    return ans;
}

int main() {
    std::vector<std::string> strs = {"eat", "tea", "tan", "ate", "nat", "bat"};
    std::vector<std::vector<std::string>> result = groupAnagrams(strs);

    // Print the result
    for (const auto &group : result) {
        for (const auto &word : group) {
            std::cout << word << " ";
        }
        std::cout << std::endl;
    }
    return 0;
}
