// WRONG

#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define int long long

const int MOD = 1e9 + 7;
const int INF = LLONG_MAX >> 1;

string str;

vector<vector<int>> dp(200000, vector<int> (2, 0)); // dp array for all tc

void solve() {
    int n = str.size();

    // state: dp[i][0] -> no of UD subsequences from ind 0 to i, ending with 'a'
    // dp[i][1] -> no of UD subsequences from ind 0 to i, ending with 'ab'

    // bc
    int finalAns = 0;
    if(str[0] == 'a') {
        dp[0][0] = 1;
        finalAns += 1;
    } 


    for(int i = 1; i < n; i++) {
        // transition: for dp[i][0] and dp[i][1]

        if(str[i] == 'a') {
            // i.e solving for dp[i][0]

            // previosly check how many UD sub ending with 'a' are there: to them only we can attach 'a' and form a UD sub
            for(int j = 0; j < i; j++) {
                if(dp[j][0] > 0) {
                    dp[i][0] = (dp[i][0] + dp[j][0]) % MOD;
                }
            }
        }
        else {
            // str[i] == 'b'

            // solving for dp[i][1]

            // so previously check for how many UD subs were ending with 'ab': to them only we can attach 'ab'
            for(int j = 0; j < i; j++) {
                // find ending with 'a'
                    // then prior to that find ending with 'ab'
                if(str[j] == 'a') {

                    for(int k = 0; k < j; k++) {
                        // find no of UD subs ending with 'ab': to that we can attach 'ab'

                        if(dp[k][1] > 0) {
                            dp[i][1] = (dp[i][1] + dp[k][1]) % MOD;
                        }
                    }
                }
            }
        }

        finalAns = (((finalAns + dp[i][0]) % MOD) + dp[i][1]) % MOD;
    }

    cout << finalAns << endl;
}

signed main()
{
    ios::sync_with_stdio(false); cin.tie(NULL);

    int t;
    cin >> t;

    while(t--) {
        cin >> str;
        solve();
    }

    return 0;
}