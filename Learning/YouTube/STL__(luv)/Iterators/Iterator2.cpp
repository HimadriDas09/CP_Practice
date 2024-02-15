#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define int long long
#define nl cout << endl

const int MOD = 1e9 + 7;
const int INF = LLONG_MAX >> 1;

signed main()
{
    ios::sync_with_stdio(false); cin.tie(NULL);

    vector<int> v = {2,3,5,6,7};

    // iterate vector
    vector<int> :: iterator it;
    for(it = v.begin(); it != v.end(); it++) {
        cout << *(it) << " "; // v.begin(), v.end() are addresses
    }
    nl;

    // NOTE 1): for(data tyep of el el: v) => el contains copies of each elem of vector (&& not points to address)
        // we can also pass references to elem by using &

    for(int &elem: v) {
        // pass by ref
        elem++;
        // cout << elem << " ";
    }
    nl;

    for(int elem: v) {
        // pass by values
        cout << elem << " ";
    }
    nl;

    // NOTE 2) Usage of "auto" keyword > automatically detects any type of variable including iterators
    vector<pair<int,int>> vp = {{1,2}, {3,4}};
    // else would have to declare =>
        // vector<pair<int,int>> :: iterator it;
        // for(auto it = vp.begin(); it != vp.end(); it++) {

        // }

    for(auto it: vp) {
        // it contains a copy of elem of the vector pair
        cout << it.first << " " << it.second << " ";
    }
    nl;

    return 0;
}