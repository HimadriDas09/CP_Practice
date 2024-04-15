// constructive thinking

#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define int long long

const int MOD = 1e9 + 7;
const int INF = LLONG_MAX >> 1;

int a,b;
int kx, ky, qx, qy;

int matching_position_of_knight_to_eat_queen(int qx, int qy, set<pair<int,int>> &knight_eat_king_pos, vector<int> &A, vector<int> &B) {
    int cnt = 0;

    // find all knight combination to eat queen
    for(int i = 0; i < 2; i++) {
        for(int j = 0; j < 2; j++) {
            pair<int,int> p = {qx + A[i], qy + B[j]};

            if(knight_eat_king_pos.find(p) != knight_eat_king_pos.end()) {
                cnt++;
                // this point counted: so remove it 
                knight_eat_king_pos.erase(p);
            }
        }
    }

    for(int i = 0; i < 2; i++) {
        for(int j = 0; j < 2; j++) {
            pair<int,int> p = {qx + B[i], qy + A[j]};

            if(knight_eat_king_pos.find(p) != knight_eat_king_pos.end()) {
                cnt++;

                // this point counted once: so delete
                knight_eat_king_pos.erase(p);
            }
        }
    }

    return cnt;
}

void solve() {
    set<pair<int,int>> knight_eat_king_pos; // x,y

    // [-b,+b], [a, -a]
    vector<int> A = {a, -a};
    vector<int> B = {b, -b};

    // insert all possible knight combinations
    for(int i = 0; i < 2; i++) {
        for(int j = 0; j < 2; j++) {
            knight_eat_king_pos.insert({kx + A[i], ky + B[j]});
        }
    }

    for(int i = 0; i < 2; i++) {
        for(int j = 0; j < 2; j++) {
            knight_eat_king_pos.insert({kx + B[i], ky + A[j]});
        }
    }

    int posCnt = matching_position_of_knight_to_eat_queen(qx, qy, knight_eat_king_pos, A, B);

    cout << posCnt << endl;

}

signed main()
{
    ios::sync_with_stdio(false); cin.tie(NULL);

    int t;
    cin >> t;
    while(t--) {
        cin >> a >> b;
        cin >> kx >> ky;
        cin >> qx >> qy;

        solve();
    }

    return 0;
}