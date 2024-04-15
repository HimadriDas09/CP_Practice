#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define int long long

const int MOD = 1e9 + 7;
const int INF = LLONG_MAX >> 1;

void solve(vector<int> &arr) {
    int n = arr.size();

    int minDelta = 1e6;

    // 1 oper: reduce or inc no by 1: then what is min no of opern to make product of all nos = 0 === no closest to 0 takes min no of operations to be reduced to 0, thus making whole product 0.

    for(int i = 0; i < n; i++) {
        if(arr[i] == 0) {
            cout << 0 << endl;
            return;
        }

        int val = arr[i];

        if(val < 0) val = -val;

        minDelta = min(minDelta, val);
    }

    cout << minDelta << endl;
}

signed main()
{
    ios::sync_with_stdio(false); cin.tie(NULL);

    int n;
    cin >> n;

    vector<int> arr(n);
    for(int i = 0; i < n; i++) cin >> arr[i];

    solve(arr);

    return 0;
}