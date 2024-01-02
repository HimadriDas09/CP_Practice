#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define int long long

const int MOD = 1e9 + 7;
const int INF = LLONG_MAX >> 1;

/* if n can be expressed as sum of k +ve odd nos or not ?

    n is even
        - k is even
            - even no of odd nos sums up to even no => ans: YES

        - k is odd
            - odd no of odd nos => always sums up to odd no => ans: NO

    n is odd 
        - k is even
            - sum of odd no => even no of times => even no => ans : NO

        - k is odd
            - sum of odd no => odd no of times => odd no => ans : YES
*/


signed main()
{
    ios::sync_with_stdio(false); cin.tie(NULL);

    int t; cin >> t;
    while(t--) {
        int n,k;
        cin >> n >> k;

        

    }

    return 0;
}