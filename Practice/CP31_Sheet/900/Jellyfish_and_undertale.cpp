// wrong
#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define int long long

const int MOD = 1e9 + 7;
const int INF = LLONG_MAX >> 1;

int a,b,n;
vector<int> arr(100);

void solve() {
    // sort the arr in dec order: so that we can delay timeout i.e bomb blast, i.e maximizing (1 + xi) and then dec it by 1 
    sort(arr.begin(), arr.end(), greater<int>());

    int timer = b, time = 0;

    for(int i = 0; i < n; i++) {
        if(timer + arr[i] > a) {
            // wait till timer reduces to 1
            time += (timer-1);

            timer = min(1 + arr[i], a);
        }
        else {
            // i.e timer + arr[i] <= a : so use this tool to inc time
            timer = min(timer + arr[i], a);
        }

        timer--; // 1 sec also passed
        time++;

        if(timer == 0) break;
    }

    cout << (timer + time) << endl;
}


signed main()
{
    ios::sync_with_stdio(false); cin.tie(NULL);

    int t;
    cin >> t;

    while(t--) {
        cin >> a >> b >> n;

        for(int i = 0; i < n; i++) cin >> arr[i];

        solve();
    }

    return 0;
}