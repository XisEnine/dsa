#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int totalFruit(vector<int>& fruits) {
    int cnt = 0;
    unordered_map<int, int> freq; // Track count of each fruit type
    int left = 0, right = 0;
    int n = fruits.size();

    while (right < n) {
        freq[fruits[right]]++; // Add the fruit at right
        
        while (freq.size() > 2) { // More than 2 unique fruits → shrink window
            freq[fruits[left]]--; // Decrease count of left fruit
            if (freq[fruits[left]] == 0) {
                freq.erase(fruits[left]); // Remove fruit if count reaches zero
            }
            left++; // Move left pointer to shrink window
        }

        cnt = max(cnt, right - left + 1); // Update max window size
        right++; // Expand window
    }
    
    return cnt;
}

int main() {
    vector<int> fruits = {1, 2, 1, 2, 3}; // Example test case
    cout << "Maximum number of fruits that can be picked: " << totalFruit(fruits) << endl;
    return 0;
}
