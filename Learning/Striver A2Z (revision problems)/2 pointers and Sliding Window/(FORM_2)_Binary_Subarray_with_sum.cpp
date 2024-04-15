#include<bits/stdc++.h>
using namespace std;

// FORM 2

/*
    M1) prefix sum + hashing
    M2) TC: O(4n), SC: O(1) => most optimized
    
    - Sliding window cannot be directly applied to solve this problem. Bcz of direct sliding window we end up missing a lot of valid windows.

        - bcz accoring to sl: if invalid window: keep on dec window size till window is valid. So definitely multiple definitely we skip a lot different [si..ei].

    - (#subarr with sum == goal) = (#subarr with sum <= goal - #subarr with sum <= goal-1)
*/
class Solution {
public:
    long long subarr_cnt_with_sum_less_equals_goal(vector<int> &nums, int goal) {

        // if goal < 0
        if(goal < 0) return 0;

        // for every valid window i.e with sum <= goals: no of valid subarrays ending at ei = ei-si+1 

        int n = nums.size();
        int si = 0, ei = 0, cur_sum = 0;
        long long cnt = 0;

        while(ei < n) {
            // update window: i.e sum of current window
            cur_sum += nums[ei];

            // invalid window: dec window size
            while(cur_sum > goal) {
                cur_sum -= nums[si];
                si++;
            }

            // since valid window: update cnt
            cnt += (ei-si+1);

            // inc window size
            ei++;
        }
        return cnt;
    }

    int numSubarraysWithSum(vector<int>& nums, int goal) {
        return subarr_cnt_with_sum_less_equals_goal(nums, goal)-subarr_cnt_with_sum_less_equals_goal(nums, goal-1);
    }
};