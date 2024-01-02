#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define int long long

const int MOD = 1e9 + 7;
const int INF = LLONG_MAX >> 1;

int n,k;
int arr[100000];

void solve() {
    // dp array
    vector<int> dp(n+1, 1e9);

    // state: dp[i]: min cost to travel from ith stone to nth stone
    // bc: already at nth stone: cost = 0
    dp[n] = 0;

    for(int i = n-1; i >= 1; i--) {
        // state: dp[i]
        // transition: all possibilities at the ith stone : take k jumps
        for(int j = 1; j <= k; j++) {
            if(i + j > n) break;
            else {
                // from ith stone => jumped to (i+j)th stone && now we'll jump further from (i+j)th stone only
                dp[i] = min(dp[i], abs(arr[i-1]-arr[i+j-1]) + dp[i+j]);
            }
        }
    }

    cout << dp[1] << endl;
}

signed main()
{
    ios::sync_with_stdio(false); cin.tie(NULL);

    cin >> n >> k;
    for(int i = 0; i < n; i++) cin >> arr[i];
    solve();

    return 0;
}