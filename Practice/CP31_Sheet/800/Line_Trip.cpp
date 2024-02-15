// for loop
#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define int long long

const int MOD = 1e9 + 7;
const int INF = LLONG_MAX >> 1;

int n,x;
int gasStationCoord[50];

void solve() {
    // there is atleast 1 station in between 
    int maxConsecutiveDistance = max(gasStationCoord[0]-0, 2*(x-gasStationCoord[n-1]));

    if(n > 1) {

        for(int i = 1; i < n; i++) {
            maxConsecutiveDistance = max(maxConsecutiveDistance, gasStationCoord[i]-gasStationCoord[i-1]);
        }
    }

    cout << maxConsecutiveDistance << endl;
}

signed main()
{
    ios::sync_with_stdio(false); cin.tie(NULL);

    int t;
    cin >> t;
    while(t--) {
        cin >> n >> x;
        for(int i = 0; i < n; i++) cin >> gasStationCoord[i];
        solve();
    }

    return 0;
}