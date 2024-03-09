// Space Optimized: bcz: optimal carrying on your required information && not maintaining not so useful information

#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define int long long

const int MOD = 1e8;
const int INF = LLONG_MAX >> 1;

int n1, n2, k1, k2; // footmen, horsemen, max cons footmen, max cons horsemen

vector<vector<vector<vector<int>>>> dp(101, vector<vector<vector<int>>> (101, vector<vector<int>> (11, vector<int> (2, 0))));

int solve() {
    // How did I think of the State ? 

        // i.e basically State contains (minimum information we need to carry along with ourselves to solve the problem according to brute force).

        // Process:

        /* 
        - totol n1+n2 troops: so total n1 + n2 places to put troops in, at each place: either place 'F' or 'H'.
            => so might need to maintain index

        - we can place 'f' or 'h' if we know we have how many 'f' or 'h' left: so maintain remaining f and h.
            => if we know above: then we know at which index we're: so no need to maintain index.

        - Suppose we're in middle of a configuration/ we're at ith ind: then we also need to know "how many consequtive 'f' or 'h' are just behind" so we need to maintain both: but it can either be of a single type.
            => so maintain the magnitude of prev consecutive troop cnt of a single type && to know the type we can setup a 2 sized vector. 0 -> footmen, 1 -> horsemen.

        */

    // State: dp[f][h][c][0/1]: no of MORE arrangements possible using rem footmen = f, rem horsemen = h, such that prev consecutive footmen (for 0) = c Or horsemen(for 1) = c.

    // bc:
        // when rem space to fill is 1: i.e either can fill 'f' or 'h': if can fill either of them then: no of more arrangements that can be formed is 1

    // move from smaller problem to bigger problem
    for(int f = 0; f <= n1; f++) { // rem f
        for(int h = 0; h <= n2; h++) { // rem h

            if(f == 0 && h == 0) continue; // bcz according to our state: we can't answer this 


            // bc:
            // when we can either put anything at last posn: that is an arrangement i.e to the state we could supply 1 more arrangement
            if(f + h == 1) {
                for(int c = 1; c <= k1; c++) {
                    if(c < k1) dp[f][h][c][0] = 1; // put 'f'
                    else if(h > 0) dp[f][h][c][0] = 1; // put 'h'
                }
                for(int c = 1; c <= k2; c++) {
                    if(c < k2) dp[f][h][c][1] = 1; // put 'h'
                    else if(f > 0) dp[f][h][c][1] = 1; // put 'f'
                }
            }
            else {

                // c == 0: doesn't make sense: bcz else are there 'horsemens' then, So handle them in horsemen.
                for(int c = 1; c <= k1; c++) { // for footmen: 'c' can go till k1
                    // transition: dp[f][h][c][0]
                        // can put 'f' or 'h': since rem f/h is > 0
                    int arg1 = 0;
                    if(c < k1) {
                        // put f: since prev cons f is < k1
                        arg1 = f-1 >= 0 ? (dp[f-1][h][c+1][0]) % MOD : 0;
                    }
                    // put h: since rem h > 0
                    int arg2 = h-1 >= 0 ? (dp[f][h-1][1][1]) % MOD : 0;

                    dp[f][h][c][0] = (arg1 + arg2) % MOD;
                }

                for(int c = 1; c <= k2; c++) { // horsemen: 'c' can go till k2
                    // transition: dp[f][h][c][1]
                        // can put 'f' or 'h'
                    int arg1 = 0;
                    // since 'c' cons horsemen just before
                    if(c < k2) {
                        // can put a 'h'
                        arg1 = h-1 >= 0 ? (dp[f][h-1][c+1][1]) % MOD : 0;
                    }
                    // since f > 0: can put a 'f'
                    int arg2 = f-1 >= 0 ?  (dp[f-1][h][1][0]) % MOD : 0;

                    dp[f][h][c][1] = (arg1 + arg2) % MOD;
                }
            }
        }
    }

    // finalSubproblem: based on our state:
        // dp[f][h][c][0/1]: no of MORE arr such that rem f = f, rem h = h, prev consecutive f are c (for 0) Or prev cons h are c (for 1).

    int ans = (dp[n1-1][n2][1][0] + dp[n1][n2-1][1][1]) % MOD;

    return ans;
}

signed main()
{
    ios::sync_with_stdio(false); cin.tie(NULL);

    cin >> n1 >> n2 >> k1 >> k2;
    cout << solve() << endl; 

    return 0;
}