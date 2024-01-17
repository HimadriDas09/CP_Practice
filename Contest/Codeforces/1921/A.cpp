#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define int long long

const int MOD = 1e9 + 7;
const int INF = LLONG_MAX >> 1;

signed main()
{
    ios::sync_with_stdio(false); cin.tie(NULL);

    int t;
    cin >> t;
    while(t--) {
        // for each test case: 4 inputs 
        unordered_map<int,int> mp; // find difference in y for same x;
        int counter = 4, side = 0;

        while(counter--) {
            int a, b;
            cin >> a >> b;
            if(mp.count(a)) {
                // so for same x, we got 2 different y
                side = abs(mp[a]-b);
            }
            mp[a] = b;
        }
        cout << (side*side) << endl;
    }

    return 0;
}