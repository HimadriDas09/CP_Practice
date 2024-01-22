#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define int long long

const int MOD = 1e9 + 7;
const int INF = LLONG_MAX >> 1;

int n; 

// if dp[i]: len of largest divisible subset till ind i
// then find at which ind: does the largest divisible subset ends
// then we must have, prior to ind i, which ind is in subset, so keep an hash array

vector<int> largestDivisibleSubset(vector<int>& nums) {
    int n  = nums.size();
    vector<int> arr = nums;
    sort(arr.begin(), arr.end()); // if sorted: then if largest elem of a divisible subset elem j is divible by elem i: then all smaller elem are div by elem i: all smaller elem are factors of elem j

    vector<int> dp(n, 1); // least possible div subset len ending at ind i
    vector<int> hash(n); // by default: hash[i] = i; contains ind prior to i in cur divisible susbset

    // state: dp[i]: len of largest divisible subset from ind 0 to i
    for(int i = 0; i < n; i++) {

        hash[i] = i; // by default
        // bc
        if(i == 0) {
            dp[i] = 1;
        }
        else {
            // transition: 

            for(int j = 0; j < i; j++) {
                if(arr[i] % arr[j] == 0) {
                    if(dp[i] < 1 + dp[j]) {
                        // then update: bcz we need max value in dp[i]
                        dp[i] = 1 + dp[j];
                        hash[i] = j; // if this selected as final subset: then prior to i there is elem j
                    }
                }
            }
        }
    }

    // now find largest div subset len's ind
    int maxLen = 0, ind = 0;
    for(int i = 0; i < n; i++) {
        if(dp[i] > maxLen) {
            maxLen = dp[i];
            ind = i;
        }
    }

    // backtrack in hash array to find the largest div subset
    vector<int> ans;
    for(int i = ind; i >= 0; ) {
        ans.push_back(arr[i]);
        if(i == hash[i]) break; // after pushing 1st elem of subset in which hash[i] == i; then break out
        i = hash[i];
    }

    reverse(ans.begin(), ans.end());
    return ans;
}


signed main()
{
    ios::sync_with_stdio(false); cin.tie(NULL);

    cin >> n;
    vector<int> nums;
    int val;

    for(int i = 0; i < n; i++) {
        cin >> val;
        nums.push_back(val);
    }

    vector<int> ans = largestDivisibleSubset(nums);
    for(auto it: ans) cout << it << " ";

    return 0;
}