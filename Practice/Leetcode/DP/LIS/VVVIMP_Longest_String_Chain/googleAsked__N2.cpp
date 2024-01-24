// TC: O(nlogn) + O(n2)


// we can pick from anywhere: bcz it's mentioned string chain is a sequence of string i.e subset && not a subsequence(i.e order to maintain)

#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define int long long

const int MOD = 1e9 + 7;
const int INF = LLONG_MAX >> 1;

bool cmp(string s1, string s2) {
    // to sort in inc order of len: i.e when len in inc order: don't do anything
    // when true: then don't need to swap s1,s2
    // when false: swap s1,s2 (default behaviour of comparitor fn)
    return s1.size() < s2.size(); 
    // shortcut: just write the comparison needed in sorted product
}   

bool checkPossible(string &s1, string &s2) {
    // 1 len difference between s1 and s2: with s1 > s2: iterate both if different char just skip in s1: else keep on moving: both pointers should reach end together
    int first = 0, second = 0;

    // stop: when any one string exhausts: both should exhausts together
    while(first < s1.size()) {
        if(second < s2.size() && s1[first] == s2[second]) {
            first++;
            second++;
        }
        else {
            // extra char present in s1
            first++;
        }
    }

    return first == s1.size() && second == s2.size();
}

int longestStrChain(vector<string>& words) {
    int n = words.size();
    vector<string> arr = words;
    // sort words acc to len of each word: imp bcz we need to get the longest valid subset: if sorted acc to inc len of words
    // we need to only look left from i for predecessors of word i
    // and if str j is a predecessor of str i: then also have access to longest chain ending at j, but we still check complete left bcz there could me multiple string chain eligible from str i

    sort(arr.begin(), arr.end(), cmp);

    // unordered_map<char,int> mp; // to store all char of str i => no map bcz sequence also matters and not just presence of char
    int maxi = 0;

    vector<int> dp(n, 1);
    // state: dp[i]: longest string chain ending at ind i

    for(int i = 0; i < n; i++) {

        // transition to determine dp[i]:

            // last member of eligible string chain i.e str j for addition of str i: there'd be a 1 char difference between their size and all char of str j will be present in str i

        for(int j = 0; j < i; j++) {

            if(arr[i].size() == arr[j].size()+1) {
                // now sequence of characters matters
                    // so one by one remove 1 char of str i and check with str j
                    // if any one match: then update dp[i], else don't

                // M1) O(16) = constant

                // bool match = false;
                // string predecessor = arr[j]; // to check if arr[j] is pred of arr[i]
                // string curString = ""; // after taking out 1 char from arr[i]

                // int k = arr[i].size(); // size of jth string


                // for(int c = 0; c < k; c++) {
                //     // remove cth char and compare with arr[j]
                //         // substr(0, c) + substr(c+1, k-(c+1))
                //     if(c > 0) curString = arr[i].substr(0,c);
                //     if(c+1 < k) curString += arr[i].substr(c+1, k-(c+1));

                //     if(curString == arr[j]) {
                //         match = true;
                //         break;
                //     }

                //     curString = ""; // reset
                // }
                
                // if(match) {
                //     // i.e arr[j] is predecessor of arr[i]
                //     dp[i] = max(dp[i], 1 + dp[j]);
                // }

                // M2: since we're considering only 1 len diff string: it can be done using 2 pointers
                if(checkPossible(arr[i], arr[j]) && dp[i] < 1 + dp[j]) {
                    dp[i] = 1 + dp[j];
                }
            }
        }

        maxi = max(maxi, dp[i]);
    }

    return maxi; 

}

signed main()
{
    ios::sync_with_stdio(false); cin.tie(NULL);

    int n;
    cin >> n;
    vector<string> words(n);

    for(int i = 0; i < n; i++) {
        cin >> words[i];
    }

    cout << longestStrChain(words) << endl;

    return 0;
}