// xor all the unique pairs and return the sum of (xor of each unique pair)
    // 2 <= n <= 1e3, 0 <= ai <= 2 power 60 i.e withing long long range(which has 64 bits)

    // M1) generate all pairs: xor each of them and sum it all : O(n2): TLE

    // M2) eg: [1,3,4,6,2]
        // (1^3) + (1^4) + (1^6) + (1^2) + (3^4) + ....
            // each xor is (sum of power of 2)  which contributes to overall sum
                // for ith bit: among all the n numbers: find the set bit cnt and unset bit cnt: xor that contributes to sum is (set bit cnt * unset bit cnt)*(1LL << i) is the contribution to final sum by the ith bit

                // (set bit cnt * unset bit cnt) => no of unique pairs whose xor of ith bit = 1


#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define int long long

const int MOD = 1e9 + 7;
const int INF = LLONG_MAX >> 1;

int n;
int arr[300000];

void solve() {
    int tot_sum = 0;

    for(int b = 0; b < 64; b++) {
        // explore the ith bit of all the n numbers && find how many of them are set
        int set_bth_bit_cnt = 0, unset_bth_bit_cnt = 0;
        for(int i = 0; i < n; i++) {
            if(arr[i] & (1LL << b)) {
                // set bit 
                set_bth_bit_cnt++;
            }
            else {
                unset_bth_bit_cnt++;
            }
        }

        // contribution to total sum
        int contr = (((unset_bth_bit_cnt*set_bth_bit_cnt) % MOD)*((1LL << b)% MOD)) % MOD;
        tot_sum = ((tot_sum % MOD) + (contr % MOD)) % MOD;
    }

    cout << tot_sum << endl;
}

signed main()
{
    ios::sync_with_stdio(false); cin.tie(NULL);

    cin >> n;
    for(int i = 0; i < n; i++) cin >> arr[i];

    solve();

    return 0;
}