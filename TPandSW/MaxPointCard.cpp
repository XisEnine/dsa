#include <iostream>
#include <vector>

using namespace std;

int maxScore(vector<int> &cardPoints,int k){
	int maxi = 0;
	int lsum = 0;
	int rsum = 0,rIndex = cardPoints.size() - 1;
	// first we calculated the sum from the front
	for(int i =0 ; i <= k - 1 ;i += 1) lsum += cardPoints[i];
	maxi = lsum;
	// now we will shrink from front and calculate from back and then give check the max sum
	for(int i = k - 1; i >= 0; i -= 1){
		lsum -= cardPoints[i];
		rsum += cardPoints[rIndex];
		rIndex -= 1;
		maxi = max(maxi,rsum+lsum);
	}
	return maxi;
}

int main(){
	vector<int> cards = {6,2,3,4,7,2,1,7,1};
	int k = 4;
	int res = maxScore(cards, k);
	cout << res <<endl;
	return 0;
}
