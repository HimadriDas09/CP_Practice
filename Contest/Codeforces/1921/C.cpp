#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define int long long

const int MOD = 1e9 + 7;
const int INF = LLONG_MAX >> 1;

int n,f,a,b;
int moments[200000];

// greedy
void solve() {
    int charge_left = f;
    int prev_moment = 0;

    for(int i = 0; i < n; i++) {
        // send a message at the ith moment
        if(charge_left <= 0) {
            cout << "NO" << endl;
            return;
        }

        // explore both the option: whichever takes less charge use it
        int option1 = (moments[i]-prev_moment)*a;
        int option2 = b; // kept it off from prev moment to moment[i] and at that instant sent the message

        int lesser_charge_consumption = min(option1, option2);
        if(charge_left > lesser_charge_consumption) {
            // charge left > consumption: bcz at that moment battery dies so we cannot send the message
            charge_left -= lesser_charge_consumption;
            prev_moment = moments[i];
        }
        else {
            // battery died: cannot send this message
            cout << "NO" << endl;
            return;
        }
    }

    cout << "YES" << endl;
}

signed main()
{
    ios::sync_with_stdio(false); cin.tie(NULL);

    int t;
    cin >> t;
    while(t--) {
        cin >> n >> f >> a >> b;
        for(int i = 0; i < n; i++) cin >> moments[i];
        solve();
    }

    return 0;
}