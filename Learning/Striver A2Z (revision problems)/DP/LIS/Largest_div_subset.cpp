#include<bits/stdc++.h>
using namespace std;

// TC: O(nLog(n)) + O(n2)
// SC: O(2n)

class Solution {
public:
    /*

    APPROACH:

    - recusion : since explore all subsets

    - subset: order not important

    - since if elems are in unsorted order: then even if we've evaluated (len of largest div subset till ith ind): then to check which subset should arr[i+1] be a part of (among all the subsets we've generated so far: for each of them : we would've to check if every elem of the subset is divisible or not).

    - why find len ? and not directly larget divisible subset

        - bcz to find to which subset can ith elem be a part of: we'd have needed to store every subset till i-1th elem and check the last elem of every subset and then append it.

        - after finding 'len', since we're storing hash[i] = 'prev elem ind of the subset ending at arr[i]'. so we can find the subset in O(n) with SC: O(2n)

    - But if sorted: if arr[i] divides the last elem of a subset then it divides all the elem of the subset.

    */
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end()); // O(n*log(n))

        // state: dp[i]: len of the largest divisible subset ending at ith ind

        vector<int> dp(n, 1); // bc covered
        vector<int> hash(n);
        int largest_subset_len = 1, largest_subset_lastInd = 0;

        // store default values in hash
        for(int i = 0; i < n; i++) hash[i] = i;
        // hash[i] = i means there is not elem prior to arr[i] in current subset

        for(int i = 1; i < n; i++) {

            // transition for dp[i]:
            for(int j = 0; j < i; j++) {
                if(nums[i] % nums[j] == 0) {
                    // nums[i] can be a part of subsequence
                    // if we get a greater dp[i] value then update value of hash[i]
                    if(1 + dp[j] > dp[i]) {
                        dp[i] = 1 + dp[j];
                        hash[i] = j;
                    }
                }
            }

            // update largest subset len && therefore last ind of it
            if(dp[i] > largest_subset_len) {
                largest_subset_len = dp[i];
                largest_subset_lastInd = i;
            }

        }


        // now store the value of largest div subset
        vector<int> ans(largest_subset_len);

        for(int i = ans.size()-1; i >= 0; i--) {
            ans[i] = (nums[largest_subset_lastInd]);

            largest_subset_lastInd = hash[largest_subset_lastInd];
        }

        return ans;

    }
};