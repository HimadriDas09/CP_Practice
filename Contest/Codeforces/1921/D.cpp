#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define int long long

const int MOD = 1e9 + 7;
const int INF = LLONG_MAX >> 1;

int n, m;
int a[200000], b[200000];

// WRONG: bcz we may pair up the same element of B with other elem of A
// void solve() {
//     priority_queue<int, vector<int>, greater<int>> minHeap; 

//     for(int i = 0; i < n; i++) {
//         for(int j = 0; j < m; j++) {
//             int diff = abs(a[i]-b[j]);
//             if(minHeap.size() > 0 && minHeap.top() < diff) {
//                 if(minHeap.size() == n) minHeap.pop();
//                 minHeap.push(diff);
//             }
//             else {
//                 // either size == 0 OR top > diff
//                 if(minHeap.size() < n) minHeap.push(diff);
//             }
//         }
//     }
//     int ans = 0;
//     int count = n;
//     while(count--) {
//         ans += minHeap.top();
//         minHeap.pop();
//     }
//     cout << ans << endl;
// }

signed main()
{
    ios::sync_with_stdio(false); cin.tie(NULL);

    int t;
    cin >> t;
    while(t--) {
        cin >> n >> m;
        for(int i = 0; i < n; i++) cin >> a[i];
        for(int i = 0; i < m; i++) cin >> b[i];
        solve();
    }

    return 0;
}