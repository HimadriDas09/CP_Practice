#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define int long long

const int MOD = 1e9 + 7;
const int INF = LLONG_MAX >> 1;

int n, k;

void solve() {
    // find the max 'x' such that k-1 * x is <= n => BS on answers

    int lo = 1, hi = n, ans = 1;

    while(lo <= hi) {
        int mid = (lo+hi)/2;

        if(mid*k <= n) {
            // save and check right
            ans = mid;
            lo = mid+1;
        }
        else {
            // check left
            hi = mid-1;
        }
    }

    // now from ans -> print all the other k-1 factors of ans
    int minVal = ans;
    for(int cnt = 0; cnt < k; cnt++) {
        cout << minVal << " ";
        minVal += ans;
    }
    cout << endl;
}

signed main()
{
    ios::sync_with_stdio(false); cin.tie(NULL);

    int t;
    cin >> t;

    while(t--) {
        cin >> n >> k;
        solve();
    }

    return 0;
}