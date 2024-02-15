/* 
    - finding all the prime factors of a given number. 
    - multiple ways to find prime factors -> Trial Division, Wheel Factorization, Sieve Method(Precomputation)
        - M1) TRIAL DIVISION:

            - NOTE: a smallest divisor of a number N is always a prime number i.e X {don't consider 1,N as divisor}, bcz if it isn't a prime i.e X is composite then it'll have factors which are prime i.e X = a*b => so a and b could also be factors of N, so X is not the smallest divisor. So, smallest divisor is always prime.

            - N = pow(prime1, a) * pow(prime2, b) * pow(prime3, c) .....
                eg: 16 = pow(2,4)*pow(3,0)*.., 
                15 = pow(3,1)*pow(5,1)*..,
                24 = pow(2,3)*pow(3,1)*pow(5,0)*pow(7,0)*..

                - We can Assume that the primes array is sorted i.e [2,3,5,7,9,11,....] and we're just raising some primes to some power then multiplying all of those terms to get N.
*/
// ---------------------------------------------------------------------------------------------
#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define int long long

const int MOD = 1e9 + 7;
const int INF = LLONG_MAX >> 1;


// or we can save all the prime factors in a vector
void primeFactorizationSave(int n) {
    unordered_map<int,int> mp; // to find factor along with their exponent

    for(int i = 2; i*i <= n; i++) {
        // is i a factor of n?
        while(n % i == 0) {
            n /= i; // take the factor out of 'n'
            mp[i]++; // and storing -> factor : exponent
        }
    }
    // is there still a factor in n
    if(n > 1) mp[n]++;

    // print out all the factors along with their exponents
    for(auto it: mp) {
        cout << "factor: " << it.first << " , exponent: " << it.second << endl;
    }
}

void primeFactorizationPrint(int n) {
    // a number when reduced has prime factors only
    // find all the prime factors of n
    for(int i = 2; i*i <= n; i++) {
        // prime factors lie between [2, sqroot of n]
        while(n % i == 0) {
            // i is a factor of n: so take out all i's from n
            cout << i << endl;
            n /= i;
        }
    }

    // now there could be a prime factor left in the product (since n is expressed as product of pow(primes, a))
    if (n != 1) cout << n << endl;
}

signed main()
{
    ios::sync_with_stdio(false); cin.tie(NULL);

    primeFactorizationSave(100);
    

}