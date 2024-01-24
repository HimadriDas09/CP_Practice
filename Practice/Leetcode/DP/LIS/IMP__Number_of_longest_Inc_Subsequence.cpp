#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define int long long

const int MOD = 1e9 + 7;
const int INF = LLONG_MAX >> 1;

int findNumberOfLIS(vector<int>& nums) {
    int n = nums.size();

    vector<int> dp(n, 1); // for state: dp[i]: len of longest IS ending at ind i
    vector<int> cnt(n, 1); // cnt of longest IS ending at ind i

    int lenLIS = 0;

    for(int i = 0; i < n; i++) {
        if(i == 0) {
            // bc
            dp[i] = 1;
            cnt[i] = 1;
        }
        else {
            // transition:
                // go to smaller indices and check to which IS can I attach nums[i]
            for(int j = 0; j < i; j++) {
                if(nums[j] < nums[i] && dp[i] < 1 + dp[j]) {
                    dp[i] = 1 + dp[j];
                    // attaching nums[i] to nums[j]: our len of LIS inc and not same
                    // no of lis ending at j is 'x': so to those lis we attach elem i: to get longer dp[i]
                    cnt[i] = cnt[j];
                }
                else if(nums[j] < nums[i] && dp[i] == 1 + dp[j]) {
                    // explored a new LIS of same len ending at ith ind
                        // so dp[i] remains same, but cnt[i] inc from it's prev value                   
                    cnt[i] += cnt[j];
                }
            }
        }

        lenLIS = max(lenLIS, dp[i]);
    }

    // now we need cnt of longest IS
        // find the LIS from dp[]
            // for all those same len LIS: return the sum of cnt
    int ans = 0;
    for(int i = 0; i < n; i++) {
        if(dp[i] == lenLIS) ans += cnt[i];
    }

    return ans;
}

signed main()
{
    ios::sync_with_stdio(false); cin.tie(NULL);

    int n;
    cin >> n;
    vector<int> nums(n);

    for(int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    cout << findNumberOfLIS(nums) << endl;

    return 0;
}