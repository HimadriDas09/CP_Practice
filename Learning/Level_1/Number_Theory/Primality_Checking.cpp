// NOTES:
/*
    1. Primality Testing: 
        - check if prime or not 
        - 3 methods:
            - Brute Force, Square Root Method, Sieve of Eratosthenes method

        - A prime no is any no which doesn't have any factor between [2,49]
        - A no is not prime: if there a factor between 2 to sqroot of n
            - sq root method


        - Sieve of Eratosthenes:

            - Can find all the prime nos upto a given limit in O(log(log N))

            - NOTE (Property of a Composite No): any composite no C, must have a prime factor P, P < C.

            - Approach: {0,1} are not prime -> so mark them, then find the next unmarked no -> it is a prime, mark at the factors of it bcz they are composite, then again find the next unmarked -> it's a prime, again follow above process.  
                - Next unmarked no is prime (bcz it doesn't have a prime factor smaller than it, else it'd have gotten marked => so it's a prime no)
*/  


/***********************************************************************/
#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define int long long

const int MOD = 1e9 + 7;
const int INF = LLONG_MAX >> 1;

bool isPrime(int n) { 
    for(int i = 2; i*i <= n; i++) // O(sqRoot N)
    /* why i goes till sqRoot(n), bcz in the factor pair of n, i is always <= sqRoot(n) */
        if(n % i == 0)
            return false;
    
    return n > 1; // if no <= 1 then not prime
}

void sieve(int n) {
    bool primes[n+1];
    fill(primes, primes+n+1, true); // initially consider all to be prime

    primes[0] = primes[1] = false; // 0,1 -> not prime

    // sieve: TC: O(N*log(log N)) OR O(N)
    // O(N(1/2 + 1/3 + 1/5 + ...))
    for(int i = 2; i*i <= n; i++) { 
        /* why i goes till sqRoot(n) -> 
        eg: n = 100, i goes till 10,But if i = 11, j starts from 121 > 100 */
        if(primes[i]) {
            // cout << i << endl;
            // ith no is prime: so mark all it's factor as composite
            for(int j = i*i; j <= n; j += i) {
                // why j = i*i and not i*2
                // j should go from j = i*2, i*3, i*4, ..... i*i
                // but 2/3/4... -> would have already marked them as composite, so we can directly start from i*i, bcz if i*i > i*2/i*3/i*4..., So i > 2/3/4.., so 2/3/4 would have already covered multiples of i < i*i.
                primes[j] = false; 
            } 
        }
        
    }
    for(int i = 0; i <= n; i++) {
        if(primes[i]) cout << i << endl;
    }
}

signed main()
{
    ios::sync_with_stdio(false); cin.tie(NULL);

    // int t, n; 
    // cin >> t;
    // while(t--) {
    //     cin >> n;
    //     cout << isPrime(n) << endl;
    // }

    sieve(100);


    return 0;
}