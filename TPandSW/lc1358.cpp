#include <iostream>
#include <unordered_map>

using namespace std;


int numOfSubstrings(string s) {
    unordered_map<char,int> mpp;
    int res = 0;
    int l = 0, n = s.size();

    for(int r = 0; r < n; r++) {
        mpp[s[r]]++;

        while (mpp['a'] > 0 && mpp['b'] > 0 && mpp['c'] > 0) {
            res += (n - r); 
			mpp[s[l]]--;
            l++;
        }
    }

    return res;
}

int main() {
  string s = "abcabc";
  int res;
  res = numOfSubstrings(s);
  cout << res << endl;
  return 0;
}
