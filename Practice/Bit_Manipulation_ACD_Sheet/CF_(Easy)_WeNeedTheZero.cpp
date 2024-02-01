// accepted

#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define int long long

const int MOD = 1e9 + 7;
const int INF = LLONG_MAX >> 1;

int arr[1000];
int n;

void solve() {
    // keep on xoring all the numbers
    int total_xor = 0;
    for(int i = 0; i < n; i++) total_xor ^= arr[i];

    if(n&1) {
        // odd => x*xor = 0; x = xor
        cout << total_xor << endl;
    }
    else {
        if(total_xor == 0) cout << 0 << endl;
        else cout << -1 << endl; // 0*xor = 0, but xor != 0 then not possible
    }
}

signed main()
{
    ios::sync_with_stdio(false); cin.tie(NULL);

    int t;
    cin >> t;
    while(t--) {

        cin >> n;
        for(int i = 0; i < n; i++) cin >> arr[i];

        solve();
    }

    return 0;
}