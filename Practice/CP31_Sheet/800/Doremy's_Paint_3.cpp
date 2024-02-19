// TEST 2 Fail on submission

// approach:
    // only possible if only 1 or 2 elem are present in array && each is present alternate to each other
        // even len array => both freq same
        // odd len array => freq1 = freq2-1
    // if all satisfies then possible else not

#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define int long long
#define py cout << "Yes" << endl
#define pn cout << "No" << endl

const int MOD = 1e9 + 7;
const int INF = LLONG_MAX >> 1;

int n;
int arr[100];
unordered_map<int,int> mp; // elem:cnt
// map elem are not stored in contiguous order

void solve() {
    for(int i = 0; i < n; i++) mp[arr[i]]++;

    if(mp.size() == 1) {
        py;
        return; 
    }
    else if(mp.size() == 2) {
        // n could be odd or even
            // 1st fetch elem1 and elem2

        auto it = mp.begin();
        pair<int,int> elem1 = {it->first, it->second}, elem2;
        // NOTE: mp.begin() is an iterator i.e address => so dereference

        for(auto it: mp) {
            if(it.first != elem1.first) {
                // we got elem2
                elem2 = {it.first, it.second};
                break;
            }
        }

        if(n&1) {
            if(elem1.second > elem2.second) {
                if(elem2.second == (elem1.second)-1) {
                    py;
                    mp.clear();
                    return;
                }
            }
            else {
                if(elem1.second == (elem2.second)-1) {
                    py;
                    mp.clear();
                    return;
                }
            }
            // if not true for if or else
            pn;
            mp.clear();
            return;
        }
        else{
            // even
            if(elem1.second == elem2.second) {
                py;
                mp.clear();
                return;
            }
            pn;
            mp.clear();
            return;
        }
    }
    pn;
    mp.clear();
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