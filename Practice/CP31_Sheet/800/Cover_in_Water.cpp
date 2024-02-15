#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define int long long

const int MOD = 1e9 + 7;
const int INF = LLONG_MAX >> 1;

int n;
string str;

// find min no of action 1 to fill all the empty cells
void solve() {
    int minOp1 = 0;

    int curEmptySubarrayLen = 0;

    // str: ...##..##.. OR ##...##..##..

    for(int i = 0; i < n; i++) {
        if(str[i] == '.') {
            curEmptySubarrayLen++;
        }
        else {
            // block encountered: based on prev empty subarray len > determine min op1 required
            if(curEmptySubarrayLen >= 3) {
                minOp1 = 2;
                break;
            }

            minOp1 += curEmptySubarrayLen;

            curEmptySubarrayLen = 0; // for next empty subarray
        }

        // if str ends with trailing '....', if you want to calculate min op1 required for ending empty subarray 
        if(i == n-1 && str[i] == '.') {
            if(curEmptySubarrayLen >= 3) {
                minOp1 = 2;
                break;
            }

            minOp1 += curEmptySubarrayLen;
        }
    }

    cout << minOp1 << endl;
}

signed main()
{
    ios::sync_with_stdio(false); cin.tie(NULL);

    int t;
    cin >> t;
    while(t--) {
        cin >> n; 
        cin >> str;
        solve();
    }

    return 0;
}