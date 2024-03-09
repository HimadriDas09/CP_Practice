/*
    Appraoch:
    ~N : would produce the 1s complement i.e revert all the bits But it would also revert the bits on the left.

    -> so make that part 0 (TRICK: & with all 0s) && revert the 1's complement of the required part (TRICK: & with all 1s)

    -> so create a binary number whose len is no of bits in N (i.e denoted by leftmost 1 position in N). 
    
    -> 1s complement = ~N & ((1 << len)-1)
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

    int len = 0;
    while(n >> len) {
        len++;
    }

    cout << (~(n) & ((1 << len) - 1)) << endl;


    return 0;
}