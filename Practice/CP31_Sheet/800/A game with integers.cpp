#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define int long long

const int MOD = 1e9 + 7;
const int INF = LLONG_MAX >> 1;

signed main()
{
    ios::sync_with_stdio(false); cin.tie(NULL);

    int t; cin >> t;
    while(t--) {
        int n;
        cin >> n;
        if(n % 3 == 0) {
            // vova wins: bcz from a multiple of 3 i.e 3x: vanya can do is 3x+1, 3x-1: vova will always revert it back to 3 till 10 moves and she wins
            cout << "Second" << endl;
        }
        else {
            // vanya wins: bcz any no between the 2 multiples of 3: can get to a 3x in 1 move
            cout << "First" << endl;
        }
    }

    return 0;
}