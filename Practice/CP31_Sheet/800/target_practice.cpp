#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define int long long

const int MOD = 1e9 + 7;
const int INF = LLONG_MAX >> 1;

char board[10][10];


void solve() 
{
    int score = 0;
    for(int i = 0; i < 10; i++) {
        for(int j = 0; j < 10; j++) {
            if(board[i][j] == 'X')
            {
                int minRowDist = i-0 < 9-i ? i : 9-i;
                int minColDist = j-0 < 9-j ? j : 9-j;

                score += (1 + (minRowDist < minColDist ? minRowDist: minColDist));
            }
        }
    }
    cout << score << endl;
}

signed main()
{
    ios::sync_with_stdio(false); cin.tie(NULL);

    int t; cin >> t;
    while(t--) {
        // input
        for(int i = 0; i < 10; i++) {
            for(int j = 0; j < 10; j++) {
                cin >> board[i][j];
            }
        }

        solve();
    }

    return 0;
}