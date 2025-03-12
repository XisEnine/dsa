#include <algorithm>
#include <climits>
#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int subarraySumOptimal(vector<int>& nums, int k) {
	unordered_map<int,int> mpp;
	mpp[0] = 1;
	int sum = 0, res = 0;
	for(int i = 0; i < nums.size();i += 1){
		sum += nums[i];
		int remain = sum - k;
		if(mpp.find(remain) != mpp.end()){
			res += mpp[remain];
		}
		mpp[sum]++;
	}
	return res;

}

int subarraySum(vector<int>& nums, int k) {
	int count = 0, length = INT_MIN,tempSum = 0;
	int l = 0, r = 0;
	int n = nums.size();
	while(r < n ){
		tempSum += nums[r];
		while(tempSum > k){
			tempSum -= nums[l];
			l += 1;
		}
		length = max(r - l + 1,length);
		r += 1;
	}
	return length;
}

int main(){
	vector<int> nums = {2,5,1,7,10};
	int k = 14;
	int res = subarraySumOptimal(nums,k);
	cout << res << endl;
	return 0;
}
