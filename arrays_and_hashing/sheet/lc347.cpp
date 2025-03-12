#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <utility>

std::vector<int> topKFrequent(std::vector<int>& nums, int k) {
    std::vector<int> result;
    
    // Step 1: Count the frequency of each number in nums
    std::unordered_map<int, int> mpp;
    for (auto it : nums) {
        mpp[it]++;
    }

    // Step 2: Store the pairs (number, frequency) into a vector
    std::vector<std::pair<int, int>> freq_vector;
    for (auto& n : mpp) {
        freq_vector.push_back(n);
    }

    // Step 3: Sort the vector by frequency in descending order
    std::sort(freq_vector.begin(), freq_vector.end(), [](const std::pair<int, int>& a, const std::pair<int, int>& b) {
        return a.second > b.second;  // Compare based on frequency
    });

    // Step 4: Get the top k frequent elements
    for (int i = 0; i < k; ++i) {
        result.push_back(freq_vector[i].first);  // Store the number (key)
    }

    return result;
}

int main() {
    std::vector<int> nums = {1, 1, 1, 2, 2, 3};
    int k = 2;
    
    // Call the topKFrequent function
    std::vector<int> top_k = topKFrequent(nums, k);

    // Output the result
    std::cout << "Top " << k << " frequent elements: ";
    for (int num : top_k) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    return 0;
}
