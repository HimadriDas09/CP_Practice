#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define int long long

const int MOD = 1e9 + 7;
const int INF = LLONG_MAX >> 1;

int n;
int arr[5000]; // values : -1e9 to 1e9 

// to maximize the score of a player: explore both the options such that your score is maximized/ other player's score is minimized 
// bcz total_score = const
void solve() {
    // dp table
    vector<vector<int>> dp(n, vector<int> (n, INF)); // To not keep garbaga: by default keeping the score to be out of range -> and check if this cell contains this value or not

    // State: dp[i][j]: max Score that a player can obtain in the subarray from ind i to ind j
    
    for(int d = 0; d < n; d++) {
        // d -> difference between i and j: so that we don't calculate for subarray of -ve len
        for(int i = 0, j = i+d; i < n && j < n; i++, j++) {
            // transition && bc
            if(i == j) {
                // 1 len sub
                dp[i][j] = arr[i];
            }
            else if(i + 1 == j) {
                // 2 len sub
                dp[i][j] = max(arr[i], arr[j]);
            }
            else {
                int opt1 = arr[i] + min(dp[i+2][j], dp[i+1][j-1]);
                int opt2 = arr[j] + min(dp[i+1][j-1], dp[i][j-2]);
                dp[i][j] = max(opt1, opt2);
            }
        }
    }
    
    // final subproblem: max score of player 1
    // since 1st chance was of p1: so it'll be max score a player can earn from ind 0 to n-1
    cout << dp[0][n-1] << endl;

}

signed main()
{
    ios::sync_with_stdio(false); cin.tie(NULL);

    cin >> n;
    for(int i = 0; i < n; i++) cin >> arr[i];
    solve();

    return 0;
}