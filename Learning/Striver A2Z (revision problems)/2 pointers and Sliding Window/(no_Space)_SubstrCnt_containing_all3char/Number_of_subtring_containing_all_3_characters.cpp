#include<bits/stdc++.h>
using namespace std;

/*
Method 1

- all 3 character: mp.size() == k => yes: with window ending at ei: then all the further window from [si..ei,ei+1,..n-1] are valid substrings.

- so once mp.size() == k: cnt += (n-ei). then in nested while(){
    decrease the window size till it's invalid
}

- then we increase window to explore more valid windows.

*/


// TC: O(2n), SC: O(3)
int numberOfSubstrings(string s) {
    int n = s.size();

    int si = 0, ei = 0, cnt = 0;

    map<char,int> mp; // char:cnt

    while(ei < n){
        // update cur window
        mp[s[ei]]++;

        // valid window: inc si till invalid
        while(mp.size() == 3) {
            // [si..ei] valid window: so starting from si, all subarr ending at ei,ei+1,ei+2,..n-1 are valid subarrays
            // so we're exploring for different si's till window is not valid

            cnt += (n-ei);

            if(mp[s[si]] == 1) mp.erase(s[si]);
            else mp[s[si]]--;

            si++;

        }

        // (here) invalid window: so inc more char in window
        
        // inc window size
        ei++;
    }

    return cnt;
}




/*
Method 2 (more optimized): STRIVER

Thought Process:

- At every index: how do we know if a valid substring end at this index ??
    ans: if prev all a,b,c has appeared.
    && how many substrings ends at ei ??: window[0..5], if smallest window containing all 3 chars and ending at ei is from [2..5] then [1,5] and [2,5] are reqd answers.


- So figure out the smallest index just that [smallest_ind...ei] has all 3 characters.

- then cnt += (smallest_ind + 1)

*/

// striver's approach
// TC: O(n), SC: O(1)
int numberOfSubstrings(string s) {
    int lastA = -1, lastB = -1, lastC = -1;

    int n = s.size(), cnt = 0;

    for(int i = 0; i < n; i++) {
        // update last index at which they appear
        if(s[i] == 'a') lastA = i;
        else if(s[i] == 'b') lastB = i;
        else lastC = i;

        // find min index: such that [min_ind...ei] contains all the 3 char
        int min_ind = min(lastC, min(lastA, lastB));

        cnt += (min_ind + 1);
    }
    return cnt;
}



