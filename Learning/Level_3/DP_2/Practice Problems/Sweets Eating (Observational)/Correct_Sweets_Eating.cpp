#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define int long long

const int MOD = 1e9 + 7;
const int INF = LLONG_MAX >> 1;

int n,m;
int sugarConc[200000];

// based on observation: dp[k] = dp[k-m] + prefix[k], if k-m >= 0. else ans = prefix[k]
void solve() {

    // sort the array: to access greater sugar conc on smaller days
    sort(sugarConc, sugarConc+n);

    // dp array
    vector<int> dp(n+1, 0);

    // prefix array
    vector<int> prefix(n+1, 0);

    for(int k = 1; k <= n; k++) {
        prefix[k] = prefix[k-1] + sugarConc[k-1];

        if(k-m >= 0) dp[k] = dp[k-m] + prefix[k];
        else dp[k] = prefix[k];
    }

    // print ans for all k
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