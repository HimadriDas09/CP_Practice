// similar to CSES array description
#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define int long long

const int MOD = 1e9 + 7;
const int INF = LLONG_MAX >> 1;

int n;
vector<vector<int>> happiness(1e5, vector<int> (3));

void solve() {
    // dp table
    vector<vector<int>> dp(n+1, vector<int> (3));

    // state: dp[i][0] => maximum happiness taro gains from ith day to nth day, if he did 0th activity on ith day, similary we've dp[i][1], dp[i][2].

    // bc: on nth day: max happiness gained depends on activity done on nth day
    dp[n][0] = happiness[n-1][0];
    dp[n][1] = happiness[n-1][1];
    dp[n][2] = happiness[n-1][2];

    for(int day = n-1; day >= 1; day--) {
        // transition: dp[i][0] => 0th task done on ith day, so happiness from it, then we depend on dp[i+1][1] and dp[i+1][2] and take the maximum happiness from either of them => to maximize happiness
        // dp[i][j] = happiness[i-1][j] + max(dp[i+1][other j], dp[i+1][other j])

        for(int task = 0; task < 3; task++) {

            // find maximum value of dp[day+1][otherTask]
            int maxValue = 0;
            for(int otherTask = 0; otherTask < 3; otherTask++) {
                if(otherTask != task) {
                    maxValue = max(maxValue, dp[day+1][otherTask]);
                }
            }

            dp[day][task] = happiness[day-1][task] + maxValue; 
        }
    }

    // main problem : depends on state[i][j]: which is max happiness from ith day to nth day if we did jth task on ith day
    // we can do one among the 3 activities on 1th day
    int maxHappiness = max(dp[1][0], max(dp[1][1], dp[1][2]));
    cout << maxHappiness << endl;
}

signed main()
{
    ios::sync_with_stdio(false); cin.tie(NULL);

    cin >> n;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < 3; j++) cin >> happiness[i][j];
    }

    solve();

    return 0;
}