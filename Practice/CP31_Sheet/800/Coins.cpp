#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define int long long

const int MOD = 1e9 + 7;
const int INF = LLONG_MAX >> 1;

int n,k;

void solve() {
    if(!(n&1)) {
        // n: even, then for y == 0: possible
        cout << "YES" << endl;
    } 
    else if(k&1) {
        // n : odd but k: odd: n-k*y = even: multiple of 2: possible
        cout << "YES" << endl;
    }
    else {
        cout << "NO" << endl;
    }

}

signed main()
{
    ios::sync_with_stdio(false); cin.tie(NULL);

    int t; cin >> t;
    while(t--) {
        cin >> n >> k;
        solve();
    }

    return 0;
}