// TC: #states * TT of each state = n*totSum = n*1e5
// SC: n*totSum + totSum = n*1e5 + 1e5


#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define int long long

const int MOD = 1e9 + 7;
const int INF = LLONG_MAX >> 1;

vector<int> coins(100); // store value of coins
vector<int> sumPossible(1e5+1, 0); // reflect if sum is possible in this vector, at max Sum of all elem can be 1e5
// if sum x is possible then SumPossible[x] == 1;

void solve(int n, int totSum) {
    vector<vector<int>> dp(n, vector<int> (totSum+1, 0)); 
    int size = 0;
    // state: dp[i][x] = 1; if till ind i, sum x is possible; else dp[i][x] = 0;

    // bc: till ind 0, coins[0] sum is only possible or sum == 0 is possible, but acc to question don't print sum == 0
    dp[0][coins[0]] = 1;
    dp[0][0] = 1;
    sumPossible[coins[0]] = 1;
    size = 1;

    // transition: for all the possible x i.e (1 to totSum): find if till ind i, if it's possible to generate sum == x
    for(int i = 1; i < n; i++) {
        // at an ind: we have 2 choices: either pick or not pick
        // if we pick: then we could generate a sum; else if we don't pick; we still have a sum
        for(int s = 0; s <= totSum; s++) {
            // till ind i: we want to generate a sum s
                // 2 choices: either till ind i-1 we already had it, or till ind i-1 we had sum of s-coins[i]
            if(dp[i-1][s] || (s-coins[i] >= 0 && dp[i-1][s-coins[i]])) {
                dp[i][s] = 1;
                if(s > 0 && sumPossible[s] == 0) {
                    sumPossible[s] = 1;
                    size++;
                }
            }
        }
    }

    // we solved for all the unique states
    cout << size << endl;
    for(int i = 1; i <= totSum; i++) {
        if(sumPossible[i]) {
            cout << i << " ";
        }
    }
}

signed main()
{
    ios::sync_with_stdio(false); cin.tie(NULL);

    int n, totSum = 0;
    cin >> n;

    for(int i = 0; i < n; i++) {
        cin >> coins[i];
        totSum += coins[i];
    }

    solve(n, totSum);

    return 0;
}