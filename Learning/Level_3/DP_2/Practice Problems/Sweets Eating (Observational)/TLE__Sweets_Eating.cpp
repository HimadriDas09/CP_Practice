// TLE: tc: O(n2)

#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define int long long

const int MOD = 1e9 + 7;
const int INF = LLONG_MAX >> 1;

int sugarConc[200000];
int n,m; // 1 to 200000

void solve() {
    // sort the array: to easily access greater conc sweets in smaller days
    sort(sugarConc, sugarConc+n);

    // state: dp[k]: min penalty for 'k' sweets
    vector<int> dp(n+1, 0);

    // bc: bcz m is atleast 1
    dp[1] = sugarConc[0];

    for(int k = 2; k <= n; k++) {
        // transition: i.e min penalty for k sweets

        // s1) get higer conc (i.e k-1 th sweet) in smaller day i.e day 1
        int penalty = dp[k-1];
        penalty += sugarConc[k-1];
        // s2) since in a day: at max we can eat is 'm' sweets: so if we're eating so: move it to next day i.e add that sweet conc once more to penalty.
        int next_day_new_sweet_ind = (k-1)-m;
        while(next_day_new_sweet_ind >= 0) {
            penalty += sugarConc[next_day_new_sweet_ind];
            next_day_new_sweet_ind -= m; 
        }

        dp[k] = penalty;
    }

    // min penalty for all k = 1 to n
    for(int i = 1; i <= n; i++) {
        cout << dp[i] << " ";
    }
    cout << endl;
}

signed main()
{
    ios::sync_with_stdio(false); cin.tie(NULL);

    cin >> n >> m;
    for(int i = 0; i < n; i++) cin >> sugarConc[i];
    solve();

    return 0;
}