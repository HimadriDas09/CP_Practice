#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define int long long

const int MOD = 1e9 + 7;
const int INF = LLONG_MAX >> 1;

int n,k,x;

int max_size = 200000;
vector<int> pref(max_size + 1);

// fill pref
void solve() {

    for(int i = 0; i <= max_size; i++) {
        pref[i] = i;
        if(i) pref[i] += pref[i-1];
    }
}

void check() {
    // to find the pref and suff of 1st k and last k from n.
    if(pref[k] <= x && x <= (pref[n] - pref[n-k])) {
        cout << "YES" << endl;
        return;
    }
    cout << "NO" << endl;
}

signed main()
{
    ios::sync_with_stdio(false); cin.tie(NULL);

    int t;
    cin >> t;

    solve(); // O(n)

    while(t--) { // O(t)
        cin >> n >> k >> x;

        check(); // O(1)
    }

    return 0;
}