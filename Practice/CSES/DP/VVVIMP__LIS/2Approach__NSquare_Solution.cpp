// for larger input = 2*1e5 : runtime err => 1e10 tc => which is not possible => need to reduce it to n*logn

// TC: #state * tt: n*n
// SC: n*n

#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define int long long

const int MOD = 1e9 + 7;
const int INF = LLONG_MAX >> 1;

int n;
int arr[200000];

void LenLIS() {
    // dp table
    vector<vector<int>> dp(n, vector<int> (n+1, 0));

    // State: f(i,prev): len of the LIS starting from ith ind, if prev index is prev -> but ans is stored in dp[i][prev+1] bcz prev = -1 to n-1

    for(int i = n-1; i >= 0; i--) {
        for(int prev = -1; prev < n; prev++) {
            // NOTE: f(i, prev = -1) = dp[i][prev+1] -> len of LIS starting from ith index, if prev ind = -1 -> i.e nothing picked before.

            // transition

            if(i == n-1) {
                // bc
                if(prev == -1) dp[i][prev+1] = 1; // f(i, prev)
                else {
                    dp[i][prev+1] = arr[i] > arr[prev]; // 1 if arr[i] > arr[prev] else 0
                } 
            }
            else {
                // if prev == -1: may/may not pick ith ind: but we won't compare with prev ind

                int len1 = 0, len2 = 0;
                if(prev == -1 || arr[i] > arr[prev]) {
                    // pick: if 1st elem of LIS || ith elem > prev elem
                    len1 = 1 + dp[i+1][i+1]; // 1 + f(i+1, i)
                }
                // not pick
                len2 = dp[i+1][prev+1]; // f(i+1, prev)

                dp[i][prev+1] = max(len1, len2);
            
            }
        }
    }
    // finalSubproblem: f(0, -1) -> stored in dp[0][0]
    cout << dp[0][0] << endl; 
}


// state: dp[i]: len of the LIS ending at ind i

// here we can keep a track of "where did LIS ended: Therefore we can BackTrack to PRINT THE LIS"
void PrintLIS() {

}

signed main()
{
    ios::sync_with_stdio(false); cin.tie(NULL);

    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    LenLIS();
    // PrintLIS();

    return 0;
}