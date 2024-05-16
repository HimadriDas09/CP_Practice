// correct
// observation based && not bit manipulation

#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define int long long

const int MOD = 1e9 + 7;
const int INF = LLONG_MAX >> 1;

int arr[100];
int n;

// i.e in each operation we choose (l,r) and find it's xor and replace all elem with xor. Final goal is to make all elem == 0.

// we need to do it in <= 8 operations.

// for n >= 3. if we xor 1 to n-2 and replace them with xor and again do xor from n-1 to n and replace with xor. Again xor of n-2 to n and replace with xor. Again do xor of all elem. Then in 4 operations all elem are 0.

// this solution always works bcz there are multiple solution for this problem.

void solve() {
    if(n == 2) {
        // k == 2, l,r = 1 to n and again do l,r = 1 to n: to make all elem == 0
        cout << 2 << endl;
        cout << 1 << " " << n << endl;
        cout << 1 << " " << n << endl;
    }
    else {
        int p1_first, p1_second, p2_first, p2_second, p3_first, p3_second, p4_first, p4_second;
        
        p1_first = 1, p1_second = n-2;
        p2_first = n-1, p2_second = n; // always has even no of elem
        p3_first = n-2, p3_second = n; // odd no of elem
        p4_first = 1, p4_second = n;

        cout << 4 << endl;
        cout << p1_first << " " << p1_second << endl;
        cout << p2_first << " " << p2_second << endl;
        cout << p3_first << " " << p3_second << endl;
        cout << p4_first << " " << p4_second << endl;
    }
}

signed main()
{
    ios::sync_with_stdio(false); cin.tie(NULL);

    int t;
    cin >> t;

    while(t--) {
        cin >> n;
        for(int i = 0; i < n; i++) cin >> arr[i];

        solve();
    }

    return 0;
}