#include <iostream>
#include <algorithm>
using namespace std;


int lengthOfLongestSubstring(string s) {
    int cnt = 0;
    // Hash table for characters using their ASCII values
    int hash[256] = {0}; // Initialize all values to 0
    int l = 0, r = 0, n = s.size();
    
    while(r < n) {
        // While the current character already exists in our window
        while(hash[s[r]] > 0) {
            // Remove characters from the left until we remove the duplicate
            hash[s[l]] = 0;
            l++;
        }
        
        // Mark the current character as seen
        hash[s[r]] = 1;
        
        // Update maximum length found so far
        cnt = max(cnt, r - l + 1);
        
        // Move right pointer to next character
        r++;
    }
    
    return cnt;
}

int main() {
  string s = "abcabcbb";
  int res = lengthOfLongestSubstring(s);
  cout << res << endl;
  return 0;
}
