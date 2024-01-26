#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define int long long

const int MOD = 1e9 + 7;
const int INF = LLONG_MAX >> 1;

signed main()
{
    ios::sync_with_stdio(false); cin.tie(NULL);

    // bitmasking: storing values in a mask
    // eg: if vector<bool> or arr[bool]
    // to see if you've visited a state or not OR once visite we set it to 1

    // arr[curr] = 1;
    // suppose only 20 elements
    // and since there are only 32 bits in an array

    int mask = 0; // in this number only we'll store which state we've visited
    int curr = 5; 
    mask = mask | (1 << curr); // rather than doing arr[5] = 1, do unset->set the 5th bit

    // ADVANTAGE: much much faster + save a lot of space


    return 0;
}