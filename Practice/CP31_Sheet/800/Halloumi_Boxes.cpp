// sorting, greedy

#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define int long long

const int MOD = 1e9 + 7;
const int INF = LLONG_MAX >> 1;

int n,k;
int arr[100];

void solve() {

    if(n == 1) {
        cout << "YES" << endl;
        return;
    }

    // check if array is sorted or not
        // if sorted then YES
        // if not sorted && k == 1 then NO
        // if not sorted && k > 1 then with multiple swaps we can make it sorted
    bool isSorted = true;

    for(int i = 1; i < n; i++) {

        if(arr[i-1] <= arr[i]) continue;
        else {
            isSorted = false;
            break;
        }
    }

    if(isSorted) {
        cout << "YES" << endl;
        return;
    }
    if(!isSorted && k == 1) {
        cout << "NO" << endl;
        return;
    }
    // else: not sorted + k > 1 : so we can make it sorted 
    cout << "YES" << endl;
}

signed main()
{
    ios::sync_with_stdio(false); cin.tie(NULL);

    int t;
    cin >> t;
    while(t--) {
        cin >> n >> k;
        for(int i = 0; i < n; i++) cin >> arr[i];
        solve();
    }

    return 0;
}