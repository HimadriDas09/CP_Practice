/*
    THEORY:

    -> Bitmask: sequence of N bits.
    Bitmasking: is representation of a subset in binary representation.

    eg: arr[5]: [1,2,3,4,5], so consider a subset of [elem[1], elem[4], elem[5]].
    so, bitmask: 10011 > rep 0th, 4th, 5th elem in a subset

    -> we can create multiple different sized bitmask: to represent all subsets.
        -> total elem in array = n => total no of subsets that can be generated is (1 << n).
        
*/

#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define int long long

const int MOD = 1e9 + 7;
const int INF = LLONG_MAX >> 1;

signed main()
{
    ios::sync_with_stdio(false); cin.tie(NULL);

    int n; cin >> n;

    int a[n];

    for(int i = 0; i < n; i++) 
        cin >> a[i];

    for(int i = 0; i < (1 << n); i++) { 
        // i rep the ith bitmask(i.e rep of the subset): from 000000 -> 111111
            // which is of size 'n' => so from the bitmask we can check which elem are there in the subset.

        for(int j = 0; j < n; j++) {
            // using j: checking which bit is set i.e which ind elem is in subset.
            if((i >> j) & 1) {
                // jth elem is there in the subset
                cout << a[j] << " ";
            }
        }
        cout << endl;
    }

    return 0;
}