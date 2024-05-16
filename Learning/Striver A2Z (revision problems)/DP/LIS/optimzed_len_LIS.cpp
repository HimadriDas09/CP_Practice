#include<bits/stdc++.h>
using namespace std;

class Solution {
public:

    // find the pos(0 based) of smallest elem which is >= ai
        // at this posn we need to append ai
    int lowerBound(int ai, vector<int>& arr) {
        // bs on index
        int lo = 0, hi = arr.size()-1, ans = arr.size();

        // check[]: ..00001111..
        while(lo <= hi) {
            int mid = lo + (hi-lo)/2;

            if(ai <= arr[mid]) {
                // save ans = mid and check left
                ans = mid;
                hi = mid-1;
            }
            else {
                lo = mid+1;
            }
        }
        return ans;
    }
    
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size(), maxi = 1;

        // state: dp[i]: len of LIS ending at ind i
        vector<int> dp(n, 1);
        vector<int> combinedIncSub;

        // bc: atleast value of dp[i] for all i is 1

        for(int i = 0; i < n; i++) {
            // transition for dp[i]

            int pos = lowerBound(nums[i], combinedIncSub);

            if(pos < combinedIncSub.size()) {
                combinedIncSub[pos] = nums[i];
            }
            else {
                combinedIncSub.push_back(nums[i]);
            }

            dp[i] = max(dp[i], 1 + pos);

            maxi = max(maxi, dp[i]);
        }

        return maxi;
    }
};