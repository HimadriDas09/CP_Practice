#include<bits/stdc++.h>
using namespace std;

/*

q) split nums into 'k' non empty subarr such that the largest sum of any subarr is minimized.
1 <= n <= 1e3, 0 <= ai <= 1e6, 1 <= k <= min(50, n)

Approach:
- minimize(max sum of a subarr) i.e BS on ans 
- ans = max sum of a subarr: ranges from lo = max(ai)(for k == n), hi = sum of ai(for k == 1)
- on this sorted space perform a BS and create a check fn && since min(max): check[]: ..000111..

- check(x) {
    // check if we can partition into 'k' subarr such that max sum of a subarr is x.
    // i.e sum of all subarr should be <= x.
    // do sweeping approach i.e maximize partition sum such that it's just <= x. 
        // this way we're trying all ways for different mids.
    // if # partitions we create is <= k then we return 1: bcz we'll be trying for smaller mid, else we return 0.
}

*/

class Solution {
public:


    bool check(int x, vector<int> &nums, int k) {
        int n = nums.size();
        int partitions_cnt = 0, cur_partition_sum = 0;

        for(int i = 0; i < n; i++) {
            if(cur_partition_sum + nums[i] < x) {
                // add elem in cur partition
                cur_partition_sum += nums[i];

                if(i == n-1) partitions_cnt++;
            }
            else {
                if(cur_partition_sum + nums[i] == x) {
                    partitions_cnt++;
                    cur_partition_sum = 0;
                }
                else {
                    // remove last elem from cur partition: bcz at max sum can be x
                    partitions_cnt++;
                    cur_partition_sum = nums[i];

                    if(i == n-1) partitions_cnt++; 
                }

            }
            // edge cases
            if(partitions_cnt > k || cur_partition_sum > x) return false;
        }

        return partitions_cnt <= k;
    }


    int splitArray(vector<int>& nums, int k) {
        int n = nums.size();
        int lo = -1, hi = 0, ans = -1;
        for(int i = 0; i < n; i++) {
            lo = max(lo, nums[i]);
            hi += nums[i];
        }

        // check[]: ...000111..
        while(lo <= hi) {
            int mid = lo + (hi-lo)/2;

            if(check(mid, nums, k)) {
                // save ans and check left
                ans = mid, hi = mid-1;
            }
            else {
                lo = mid+1;
            }
        }

        return ans;
    }
};