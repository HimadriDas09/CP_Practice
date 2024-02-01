// accepted

// q: find the xor of a^a+1^...b

#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define int long long

const int MOD = 1e9 + 7;
const int INF = LLONG_MAX >> 1;

// NOTE: a^a = 0, a^0 = a


// Method 2) Prefix XOR
    // i.e xor of n^n-1^n-2......1
    // ans = prefix_xor(b) ^ prefix_xor(a-1)
        // why works? bcz nos from 0 to a-1 are xored to itself resulting in 0 and res^0 = res only

    // how to find prefix xor ?
        // Property of Prefix XOR:
            // based on result of (num % 4 == 1/2/3/0) we can determine the result of prefix_xor(num) 

        // Building up prefix xor till some number

        // 1^2 = 3 -> 2%4 == 2 => pref_xor(n) = n+1
        // 3^3 = 0  -> 3%4 == 3 => pref_xor(n) = 0
        // 0^4 = 4 -> 4%4 == 0  => pref_Xor(n) = n
        // 4^5 = 1 -> 5%4 == 1  => pref_xor(n) = 1

        // 1^6 = 7  -> 6%4 == 2
        // 7^7 = 0  -> 7%4 == 3
        // 0^8 = 8 -> 8%4 == 0
        // 8^9 = 1 -> 9%4 == 1


int prefix_xor(int x) {
    if(x < 0) return 0;
    if(x%4 == 2) return x+1;
    else if(x%4 == 3) return 0;
    else if(x%4 == 0) return x;
    else if(x%4 == 1) return 1;
}


void solve2(int a, int b) {
    // ans is prefix_xor(b)^prefix_xor(a-1)

    int ans = prefix_xor(b)^(a>=1 ? prefix_xor(a-1): 0);

    cout << ans << endl;
}






// Method 1) Indivial bit check for A to B

// f(A,B) = xor of all the numbers from A,A+1,...B => A,B : O to 1e12
    // so we can store it in a long long variable: 64bits
    // approach: traverse all the 64 bits
        // for each bit: from A to B: cnt the number of set bits
            // if odd: xor of ith bit = 1, else xor of ith bit = 0
                // for each bit xor result: find: res += 0/1 * (1 << i)

// TC heavy
void solve(int a, int b) {
    int res = 0;

    for(int i = 0; i < 64; i++) {
        // iterate from A to B and find set bit cnt for ith bit

        int set_cnt = 0;

        for(int no = a; no <= b; no++) {
            if(no & (1LL << i)) {
                // set bit
                set_cnt++;
            }
        }

        // if cnt of set bits = odd => xor = 1 else xor = 0
        if(set_cnt & 1) {
            // xor = 1: this bit contributes to res = res + pow(2,i)
            res += (1LL << i);
        }
        // xor = 0
    }

    cout << res << endl;

}

signed main()
{
    ios::sync_with_stdio(false); cin.tie(NULL);

    int a,b;
    cin >> a >> b;

    solve2(a,b);

    return 0;
}