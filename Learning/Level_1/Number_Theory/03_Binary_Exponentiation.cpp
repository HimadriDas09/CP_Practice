#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define int long long

const int MOD = 5;
const int INF = LLONG_MAX >> 1;

// concept is:
    // b == even:  a^b = a^(b/2) * a^(b/2) 
    // using recursion solve it: each time: to find (smt power smt) => always divide it by 2 and find it using recursion
    // if b == odd:  a^b = a^(b/2) * a^(b/2) * a

// TC: log(b)
int binaryExponentiation(int a, int b) { // a^b

    if(b == 0) return 1;

    int half_power = binaryExponentiation(a,b/2);

    if(b % 2 == 0) {
        // b: even
        return half_power * half_power;
    }
    return half_power * half_power * a;
}

int modularExponentiation(int a, int b) {
    if(b == 0) return 1;

    int half_power = modularExponentiation(a, b/2); // is returned value: so is < MOD 

    if(b % 2 == 0) {
        return (half_power * half_power) % MOD;
    }
    return (((half_power * half_power) % MOD ) * (a % MOD)) % MOD;
}

signed main()
{
    ios::sync_with_stdio(false); cin.tie(NULL);

    cout << modularExponentiation(2,10) << endl;

    return 0;
}