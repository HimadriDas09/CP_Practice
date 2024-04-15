#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define int long long

const int MOD = 1e9 + 7;
const int INF = LLONG_MAX >> 1;

int n,m;
string x,s; // len: n,m

/*
    Approach:
    - we need to apply MINIMUM multiple operation(>= 0) on x such that s is a substring of x.
    - since, min len of x = 1 && max len of s could be 25, bcz m*n <= 25. so apply that many operations such that x just excceds the len of s. i.e 1 -> 2 -> 4 -> 8 -> 16 -> 32. so 6 operations.
    - then use sliding window of fixed sized 'm' to find 's' in x i.e the 1st occurence of s. then find the ei of the window && find after how many operations this 'ei' came in existence.
    - return -1 if couldn't find using sliding window.
*/

void solve() {

    // at max 3 operation can be applied to 'x' for it to exceed len of 's' always, such that 's' will appear as a substring if it has to
    for(int op = 1; op <= 6; op++) {
        x += x;
    }   

    // sliding window of x to find s(of fixed size m)
    bool substringFound = false;

    int si = 0, xlen = x.size();

    while(si <= xlen-m) {
        if(x.substr(si, m) == s) {
            substringFound = true;
            break;
        }
        si++;
    }

    if(!substringFound) {
        cout << -1 << endl;
        return;
    }

    // we've the last si, so ei = si + m - 1
    // i.e after how many operation did this index came into existence
    int originalLenX = n, op = 0;
    for(op = 0; op <= 6; op++) {
        if(si + m - 1 <= originalLenX-1) {
            break;
        } 
        originalLenX *= 2;
    }

    cout << op << endl;
}

signed main()
{
    ios::sync_with_stdio(false); cin.tie(NULL);

    int t;
    cin >> t;
    while(t--) {
        cin >> n >> m;
        cin >> x >> s;
        solve();
    }

    return 0;
}