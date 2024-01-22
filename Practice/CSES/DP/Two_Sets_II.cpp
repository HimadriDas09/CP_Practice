// {1,2,...n} => find no of ways, this set of numbers can be divides into 2 sets of equal sum
#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define int long long

const int MOD = 1e9 + 7;
const int INF = LLONG_MAX >> 1;

int n;

// ANS = find the no of subsequences such that sum = totsum/2
void solve() {
    int totSum = (n*(n+1))/2;

    if(totSum % 2 != 0) {
        cout << 0 << endl;
        return;
    }
    // dp table
    vector<vector<int>> dp(n, vector<int>((totSum/2)+1, 0));

    // state: dp[i][tar] -> no of subsequence from ind i to n-1 such that total sum = tar

    // bc: i == n-1 -> dp[n-1][tar] -> that index n-1, what could the target be ?, target can only be 'n', at ind n-1 lies n
    dp[n-1][n] = 1;

    for(int i = n-2; i >= 0; i--) {
        for(int tar = 0; tar <= totSum/2; tar++) {
            // transition:

            if(tar == 0) dp[i][tar] = 0; // emptySet 
            else {
                // if we don't pick the ith ind elem, still rem sum = tar, but from ind i+1

                // OR we pick the ith ind elem i.e i+1: rem sum = tar-(i+1), make sure tar-(i+1) >= 0

                if(tar - (i+1) >= 0) {
                    dp[i][tar] = (dp[i][tar] + dp[i+1][tar-(i+1)]) % MOD;
                }
                dp[i][tar] = (dp[i][tar] + dp[i+1][tar]) % MOD; 
            }
        }
    }

    // final subproblem
    cout << dp[0][totSum/2] << endl;
}

signed main()
{
    ios::sync_with_stdio(false); cin.tie(NULL);

    cin >> n;
    solve();

    return 0;
}