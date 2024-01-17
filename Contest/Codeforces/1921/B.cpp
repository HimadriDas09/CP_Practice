#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define int long long

const int MOD = 1e9 + 7;
const int INF = LLONG_MAX >> 1;

int n;
string s1, s2;

void solve() {
    int zero_one = 0, one_zero = 0;
    int minOp = 0;

    // iterate s2 while comparing with s1
    for(int i = 0; i < n; i++) {
        if(s1[i] != s2[i]) {
            if(s2[i] == '1') one_zero++;
            else zero_one++;
        }
    }

    int common = min(zero_one, one_zero);
    one_zero -= common;
    zero_one -= common;

    minOp += common;

    // so either of oz or zo or both are zero now
    if(one_zero == 0) {
        minOp += zero_one;
    }   
    else if(zero_one == 0) {
        minOp += one_zero;
    } 
    // else both are same i.e 0

    cout << minOp << endl;
}


signed main()
{
    ios::sync_with_stdio(false); cin.tie(NULL);

    int t;
    cin >> t;
    while(t--) {
        cin >> n;
        cin >> s1 >> s2;

        solve();
    }

    return 0;
}