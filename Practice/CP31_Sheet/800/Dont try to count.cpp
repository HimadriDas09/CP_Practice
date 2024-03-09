#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define int long long

const int MOD = 1e9 + 7;
const int INF = LLONG_MAX >> 1;

int n,m;
string x,s; // len: n,m

void solve() {
    // traverse x: to find the 1st character of s   
        // lock it i.e a start for x: and traverse both x and s: if all match till end of s return len, else find a different start for x

    for(int i = 0; i < n; i++) {
        if(x[i] == s[0]) {
            // start traversing both x and s
            string temp_x = x, temp_s = s;
            int st_s = 0, st_x = i, op_cnt = 0, temp_x_len = n;

            while(st_x < m) {

                // temp_x exhausted
                if(st_x == temp_x_len) {
                    temp_x += temp_x;
                    // rest st_x to i and st_s to 0
                    st_x = i, st_s = 0, temp_x_len *= 2, op_cnt++;
                }

                // if not match: break and find a new start for x
                if(temp_x[st_x] != temp_s[st_s]) {
                    break;
                }

                // else 
                st_x++, st_s++;
            }

            // traverse whole string s
            if(st_s == m) {
                cout << op_cnt << endl;
                return;
            }
        }
    }
    cout << -1 << endl;
}

signed main()
{
    ios::sync_with_stdio(false); cin.tie(NULL);

    int t;
    cin >> t;
    while(t--) {
        cin >> n >> m;
        cin >> x >> s;
        solve();
    }

    return 0;
}