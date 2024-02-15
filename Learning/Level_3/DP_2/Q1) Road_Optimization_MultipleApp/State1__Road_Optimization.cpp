#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define int long long

const int MOD = 1e9 + 7;
const int INF = LLONG_MAX >> 1;

int sp_coord[500], sp_limit[500];
int n, l, k;


// MLE code:
    // so space optmization might work on it.
void solve() {
    // State: dp[x][t][r]: min time taken to go from coord x to l, such that prev speed limit is 't' i.e covering 1 km in t minutes, 'r' signs removed till now
        // by default: keep INF

    // find the max value of 't' i.e speed limit for dp table
        // which is never 0
    // and record all the coord with speed limit: so that during exploring all ways > we can check if we reached a speed limit or not

    unordered_map<int,int> coord_speedLimit; // coord: their speed limit

    int max_t = 0;
    for(int i = 0; i < n; i++) {
        coord_speedLimit[sp_coord[i]] = sp_limit[i];

        max_t = max(max_t, sp_limit[i]);
    }

    // dp table: dp[x][t][r]
        // x: 0 to l
            // t: 1 to max_t: size: [max_t+1] just don't utilize 0
                // r: 0 to k
    vector<vector<vector<int>>> dp(l+1, vector<vector<int>> (max_t+1, vector<int> (k+1, INF)));
    // atmax answer can be l*maxSpeedlimit = 1e5*1e4 = within integer range
        // no need to take MOD

    // base case: when x == l i.e already reached so time = 0
    for(int t = 1; t <= max_t; t++) {
        for(int r = k; r >= 0; r--) {
            dp[l][t][r] = 0;
        }
    }

    // transition:
    for(int x = l-1; x >= 1; x--) { // rev order

        for(int t = 1; t <= max_t; t++) { // any order

            for(int r = k; r >= 0; r--) { // rev order

                if(coord_speedLimit.count(x)) {
                    // x may be a speed limit coord
                    int time1 = INF, time2 = INF;
                    // remove the speed limit: continue with prev sp limit, r+1
                    // check if can remove
                    if(r+1 <= k) {
                        time1 = t + dp[x+1][t][r+1];
                    }

                    // don't remove this speed limit: continue with this new speed, r -> same 
                    time2 = coord_speedLimit[x] + dp[x+1][coord_speedLimit[x]][r];

                    dp[x][t][r] = min(time1, time2);
                }
                else {
                    // x may not be a speed limit coord
                        // so we travel with prev speed limit and don't remove any sign
                    dp[x][t][r] = t + dp[x+1][t][r];
                }
            }
        }

    }

    // final Subproblem calculation using states: reach from 0 to L by taking the min time and you can remove at max k speed signs

    // is there a state using which we can find the min Subproblem >
        // dp[1][sp_limit[0]][r]: min time from go from x = 1 to l, such that prev speed is sp_limit[0] which is only possible && till now at max we can remove 0/1 signs only

    int min_time = sp_limit[0] + min(dp[1][sp_limit[0]][0], k > 0 ? dp[1][sp_limit[0]][1] : INF);


    cout << min_time << endl;
}


signed main()
{
    ios::sync_with_stdio(false); cin.tie(NULL);

    cin >> n >> l >> k;
    for(int i = 0; i < n; i++) cin >> sp_coord[i];
    for(int i = 0; i < n; i++) cin >> sp_limit[i];

    solve();

    return 0;
}