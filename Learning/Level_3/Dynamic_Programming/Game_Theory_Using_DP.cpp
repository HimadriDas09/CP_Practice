/* QUESTION:
    - given n, player A, player B
    - Player A starts the game, he can choose among n-1/n-2/n-3. lets say A choose x, now it's B's turn who can choose among x-1/x-2/x-3.
    - A player loose if on his turn he gets a prime number.
    - Both player plays optimally.
    - who wins and who looses ?
*/

#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define int long long

const int MOD = 1e9 + 7;
const int INF = LLONG_MAX >> 1;

vector<bool> primes(1e6+1, true); // by default all are prime, mark composite using seive 

// determine prime using sieve method
// composite no is always a multiple of prime no
void seive(int n) {
    primes[0] = primes[1] = false; // 0,1 are not prime

    for(int i = 2; i*i <= n; i++) {
        // check if ith no is prime: mark it's multiple as composite
        if(primes[i]) {
            for(int j = i*i; j <= n; j = j+i) {
                primes[j] = false;
            }
        }
    }
}

// we'll try to make 'A' win && to make 'B' loose. Similary 'B' will do the same
void solve(int n) {
    // state: dp[n] = 1 -> winning state -> when !prime(n) && either of dp[n-1]/dp[n-2]/dp[n-3] is lossing state, then we may win.

    // dp[n] = 0 -> loosing state -> when prime(n) or all among dp[n-1],dp[n-2],dp[n-3] are in winning state.

    vector<bool> dp(n, false);
    dp[0] = dp[1] = true; // 1 is winning state

    for(int i = 2; i <= n; i++) {
        dp[i] = !primes[i] && !(dp[i-1] && dp[i-2] && dp[i-3]); 
    }

    cout << (dp[n] ? "A wins" : "A looses" )<< endl;
}

signed main()
{
    ios::sync_with_stdio(false); cin.tie(NULL);

    int n;
    cin >> n;

    seive(n);
    solve(n);

    return 0;
}