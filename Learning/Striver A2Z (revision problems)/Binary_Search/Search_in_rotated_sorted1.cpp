// TC is optimal: but could have been a better way to approach this problem i.e better code.

#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define int long long

const int MOD = 1e9 + 7;
const int INF = LLONG_MAX >> 1;

int n, target; 
vector<int> nums(5000);

void solve() {
    int lo = 0, hi = n-1, ans = -1;

    while(lo <= hi) {
        int mid = (lo + hi)/2;

        if(nums[mid] == target) {
            ans = mid;
            break;
        }

        if(nums[lo] <= nums[mid] && (nums[lo] <= target && target <= nums[mid])) {
            // sorted space + tar might be present so search left
            hi = mid-1;
        }
        else if(nums[mid] <= nums[hi] && (nums[mid] <= target && target <= nums[hi])) {
            // search right
            lo = mid+1;
        }
        else {
            // in any one of the above sorted space: target cannot be found: so maybe present in this probable unsorted space.
            // so identify which half is unsorted 
            if(nums[mid] >= nums[hi]) {
                // go right
                lo = mid+1;
            }
            else {
                // go left
                hi = mid-1;
            }
        }
    }

    cout << ans << endl;
}

signed main()
{
    ios::sync_with_stdio(false); cin.tie(NULL);

    int t; cin >> t;
    while(t--) {
        cin >> n >> target;
        for(int i = 0; i < n; i++) cin >> nums[i];

        solve();
    }

    return 0;
}