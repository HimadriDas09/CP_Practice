#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define int long long

const int MOD = 1e9 + 7;
const int INF = LLONG_MAX >> 1;

// TC: O(n2), SC: O(2n)

// arr contains all +ve values
int longestBitonicSubsequence(vector<int>& arr, int n)
{
	vector<vector<int>> dp(n, vector<int> (2, 1));
    // assign all values = 1; bcz whichever sub we're not exploring those values should correct by default for dependency of other bigger problems

    // state: dp[i][0]: len of the longest bitonic subsequence ending at ind i, with cur bitonic sub being in its inc phase

    // dp[i][1]: longest B.S from ind 0 to i, dec Phase

    // NOTE: but why not state: dp[i]: bcz we need to maintain at max 1 peek: so to control that we need to introduce "keep on maintaining inc phase/ dec it", "do not inc the dec phase"
        // and since not greedy: we need to explore everything 

    int longestBS = 0;

    // bc
    dp[0][0] = dp[0][1] = 1;

    for(int i = 1; i < n; i++) {
        // transition: for dp[i][0]: inc and dp[i][1]: dec
            // explore all the longest B.S ending at smaller indices && check to which can we attach arr[i] and based on that change the inc/dec phase

            // IMP: if inc phase -> we can go to dec phase BUT vv is not possible

        for(int j = 0; j < i; j++) {
            if(arr[j] < arr[i]) {
                // inc phase continues for dp[j]: dp[i][0]

                dp[i][0] = max(dp[i][0], 1 + dp[j][0]); 
                // if j is in dec phase: then we cannot attach arr[i]: dp[i][1] = 1 by default
            }
            else if(arr[j] > arr[i]) {
                // can attach arr[i]: 
                    // to continue dec phase of dp[j]
                    // or start the dec phase of dp[j], when it was prev in inc phase

                dp[i][1] = max(dp[i][1], max(1 + dp[j][1], 1 + dp[j][0]));
            }
        }

        longestBS = max(longestBS, max(dp[i][1], dp[i][0]));
    }

    return longestBS;
}

signed main()
{
    ios::sync_with_stdio(false); cin.tie(NULL);

    int n;
    cin >> n;
    vector<int> arr(n);

    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cout << longestBitonicSubsequence(arr, n) << endl;

    return 0;
}