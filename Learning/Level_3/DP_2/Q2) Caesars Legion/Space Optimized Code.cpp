#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define int long long

const int MOD = 1e8;
const int INF = LLONG_MAX >> 1;

int n1, n2, k1, k2; // footmen : n1,k1 && horsemen : n2,k2

void solve() {
    // state: dp[f][h][c][0] : no of ways to put 'f' footmen and 'h' horsemen more, if previously 'c' consecutive footmens are there
    // similary for [1]: if prev 'c' consecutive horsemen are there

    vector<vector<vector<vector<int>>>> dp(n1+1, vector<vector<vector<int>>> (n2+1, vector<vector<int>> (11, vector<int> (2, 0))));

    // bc: when 0 more horsemen and footmen are yet to be placed
        // for footmen i.e 0
    // for(int c = 0; c <= k1; c++) dp[0][0][c][0] = 1;

    //     // for horsemen i.e 1
    // for(int c = 0; c <= k2; c++) dp[0][0][c][1] = 1;

    // transition for dp[f][h][c][0/1]
    for(int f = 0; f <= n1; f++) {
        for(int h = 0; h <= n2; h++) {

            for(int c = 0; c <= k1; c++) {

                if(f == 0 && h == 0) dp[f][h][c][0] = 1;
                // c consecutive footmen last present i.e 0 && c < k1
                else if(c < k1) {
                    // no of ways to put 'f' and 'h', if 'c' footmen are present previously
                    int op1 = 0, op2 = 0;
                    if(f-1 >= 0) op1 = dp[f-1][h][c+1][0];
                    if(h-1 >= 0) op2 = dp[f][h-1][1][1];

                    dp[f][h][c][0] = (op1 + op2) % MOD;
                }

            }

            for(int c = 0; c <= k2; c++) {
                if(f == 0 && c == 0) dp[f][h][c][1] = 1;
                // c consecutive horsemen last present i.e 1 && c < k2
                else if(c < k2) {
                    int op1 = 0, op2 = 0;
                    if(f-1 >= 0) op1 = dp[f-1][h][1][0];
                    if(h-1 >= 0) op2 = dp[f][h-1][c+1][1];

                    dp[f][h][c][1] = (op1 + op2) % MOD;
                }
            }
        
        }
    }

    // final Subproblem
        // State: dp[f][h][c][0/1]: no of ways to put 'f' and 'h' more, if just previously 'c' troops of type 0/1 are present
    // int finalSubproblem = (dp[n1][n2][0][0] + dp[n1][n2][0][1]) % MOD; => both are same for c == 0
    cout << dp[n1][n2][0][0] << endl;
}

signed main()
{
    ios::sync_with_stdio(false); cin.tie(NULL);

    cin >> n1 >> n2 >> k1 >> k2;
  solve();

    return 0;
}