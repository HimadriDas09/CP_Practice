// TC: log(n), but not clean code

// not visualized as : ...0000011111...

// rather: kept on going the space where no of elems are odd: within lo..hi

#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define int long long

const int MOD = 1e9 + 7;
const int INF = LLONG_MAX >> 1;



class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n = nums.size();
        int neg = -1;
        
        // BS on index
        int lo = 0, hi = n-1, ans; // ans will definitely be found: bcz size of nums is always odd

        while(lo <= hi) {
            int mid = lo + (hi-lo)/2;

            // single elem might be present in the extremes
            if((mid-1 >= 0 ? nums[mid-1] : neg) != nums[mid] && nums[mid] != (mid+1 < n ? nums[mid+1] : neg)) {
                // this is single elem
                ans = nums[mid];
                break;
            }
            else if(nums[mid] == (mid-1 >= 0 ? nums[mid-1] : neg)) {
                // check which side has odd elem bcz if nums[mid] is not single elem then one between either side is supposed to have one.
                if((mid-1-lo) & 1) {
                    // go left
                    hi = mid-2;
                }
                else {
                    // go right
                    lo = mid+1;
                }
            }
            else {
                // arr[mid] == arr[mid+1]
                if((mid-lo) & 1) {
                    // go left
                    hi = mid-1;
                }
                else {
                    // go right
                    lo = mid+2;
                }
            }
        }

        return ans;
    }
};





signed main()
{
    ios::sync_with_stdio(false); cin.tie(NULL);



    return 0;
}