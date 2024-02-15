#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define int long long

const int MOD = 1e9 + 7;
const int INF = LLONG_MAX >> 1;

int n;
int arr[10];

void solve() {
    if(arr[0] == 1) {
        cout << "YES" << endl;
    }
    else {
        cout << "NO" << endl;
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