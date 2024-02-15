#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define int long long

const int MOD = 1e9 + 7;
const int INF = LLONG_MAX >> 1;

int n, l, k;
int signCoord[500], speedLimits[500];

void solve() {
    // dp table
    vector<vector<int>> dp(n, vector<int> (k+1, INF));

    // state: dp[i][rem]: min time to reach end (i.e coord 'l'), if we're currently at the ith sign and considering it && we've 'rem' no of signs that we can remove.

    // bc: reaching end from n-1th sign and choosing it, don't know how many more we can remove
    for(int rem = 0; rem <= k; rem++) dp[n-1][rem] = (l-signCoord[n-1])*speedLimits[n-1];

    for(int i = n-2; i >= 0; i--) {
        
        for(int rem = 0; rem <= k; rem++) {
            // transition for dp[i][rem]

            // consider the ith sign and choose the next sign to follow, removing all in between, considering the one from whom we take min time to the end

            for(int nxt = i+1; nxt < n; nxt++) {
                // choosing nxt sign => removing nxt-i+1 in between

                if(rem - (nxt-i-1) >= 0) {
                    dp[i][rem] = min(dp[i][rem], ((signCoord[nxt] - signCoord[i]) * speedLimits[i]) + dp[nxt][rem - (nxt-i-1)]);
                }
                else break; // bcz further also it won't be >= 0
            }

            // at the end: we also consider the option in which we remove all signs from i+1th sign and directly reach end
            if(rem-(n-i-1) >= 0) {
                dp[i][rem] = min(dp[i][rem], (l-signCoord[i])*speedLimits[i]);
            }
        }
    }

    // final subproblem for state: dp[i][rem]
    cout << dp[0][k] << endl;
}

signed main()
{
    ios::sync_with_stdio(false); cin.tie(NULL);

    cin >> n >> l >> k;
    for(int i = 0; i < n; i++) cin >> signCoord[i];
    for(int i = 0; i < n; i++) cin >> speedLimits[i];

    solve();

    return 0;
}