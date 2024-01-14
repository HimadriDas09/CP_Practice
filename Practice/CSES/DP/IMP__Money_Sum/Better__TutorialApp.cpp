#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define int long long

const int MOD = 1e9 + 7;
const int INF = LLONG_MAX >> 1;

signed main()
{
    ios::sync_with_stdio(false); cin.tie(NULL);

    int n;
    cin >> n;
    vector<int> coins(n);
    for(int i = 0; i < n; i++) cin >> coins[i];

    // what is max Possible Sum == 1e5
    vector<int> pos(1e5+1, 0);
    pos[0] = 1;

    vector<int> v;

    // since we're only concerned with the sum && not with using what elem sum is produced: so only check if this sum is earlier made or not
    // if yes: then earlier_made_sum + cur_elem is possible 
    for(auto e: coins) {
        v.clear();

        for(int s = 0; s <= 100000; s++) {
            // if sum s is possible 
            if(pos[s])
                v.push_back(s+e);
        }

        for(auto e: v) 
            pos[e] = 1;
    }

    // now push all the indices of pos in a vector
    vector<int> ans;
    for(int i = 1; i <= 100000; i++) {
        if(pos[i])
            ans.push_back(i);
    }

    cout << ans.size() << endl;
    for(int i = 0; i < ans.size(); i++) {
        cout << ans[i] << " ";
    }

    return 0;
}