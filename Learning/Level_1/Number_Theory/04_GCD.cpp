#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define int long long

const int MOD = 1e9 + 7;
const int INF = LLONG_MAX >> 1;

// NOTE: 

// LCM(a,b) = a*b/gcd(a,b)

// gcd(a,b,c,d) = gcd(gcd(gcd(a,b),c),d)
    // same is for LCM

// LCM*GCD = a*b i.e product of numbers

// gcd(i,i+1) = 1

// Euclidien Algorithm: GCD(a,b) = GCD(b%a, a) and when a == 0, solution is b
int gcd_(int a, int b) {
    if(a == 0) return b;

    return gcd(b%a, a);
}

signed main()
{
    ios::sync_with_stdio(false); cin.tie(NULL);

    cout << gcd(10,25) << endl; // in built 
    cout << gcd_(25,10) << endl;
    // both have same complexity => TC: log(n)

    return 0;
}