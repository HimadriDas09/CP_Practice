#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define int long long

const int MOD = 1e9 + 7;
const int INF = LLONG_MAX >> 1;

int n, m;
int arr[100000];

// maximization is done by BS
    // check fn: checks if x is possible or not
bool check(int x) {
    // check if x states is possible each with sum >= m
    int state_cnt = 0, cur_state_sum = 0;

    for(int i = 0; i < n; i++) {
        // adding up consecutive states to satisfy sum

        cur_state_sum += arr[i];
        if(cur_state_sum >= m) {
            state_cnt++;
            cur_state_sum = 0;
        }
    }

    return state_cnt >= x;
}

void solve() {
    // bs on answers > sweeping 
        // ans: find the max no of subarrays with sum >= m
            // min Sub = 1 > all state combined, max Sub = n > initial each state as 1 state

    int lo = 1, hi = n, ans = 1;
    while(lo <= hi) {
        int mid = (lo+hi)/2;
        if(check(mid)) {
            // i.e this many states is possible each with sum >= m
                // save it and check right
            ans = mid;
            lo = mid+1;
        }
        else {
            // check left
            hi = mid-1;
        }
    }
    cout << ans << endl;
}

signed main()
{
    ios::sync_with_stdio(false); cin.tie(NULL);

    int t;
    cin >> t;

    while(t--) {
        cin >> n >> m;
        for(int i = 0; i < n; i++) {
            cin >> arr[i];
        }

        solve();
    }

    return 0;
}