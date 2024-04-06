// longest substring with atmost k distinct char
#include<bits/stdc++.h>
using namespace std;

/*
Method 1:

can it be solved using sliding window??

- process of sliding window: inc window len till it's invalid then dec len till it's valid.

- in Some problems: the problem that arise is:
when we're decreasing window till [si..ei] is a valid window. We miss out on a solution with a lesser si and lesser ei. But (here) even if we miss them out: which is a smaller substring. 

- we've the len of a greater valid substring.

*/

// TC: O(2n)*log(n). SC: O(256)

int fn(string &s, int k){
    map<char, int> mp; // char: cnt

    int n = s.size();
    int si = 0, ei = 0, maxi = 0;

    while(ei < n) {
        // update cur window
        mp[s[ei]]++;

        // invalid window: dec size
        while(mp.size() > k) {
            if(mp[s[si]] == 1) mp.erase(s[si]);
            else mp[s[si]]--;

            si++;
        }

        // valid window: update len
        maxi = max(maxi, ei-si+1);

        // inc window size
        ei++;
    }
    return maxi;
}

/*
optimization: STRIVER

since: once we've a valid window: and we're about to start dec window size till it's a valid window. To put into consideration we now need a window > maxi.

- Now when window is invalid: which is invalid by 1 extra different character then (acc to prev process we used to jump into the nested while loop, keeping (ei) fixed) even if we dec window len (at best): we'll get a window len <= maxi. 

- So just by si++, window is of len maxi. then we can slide a window of fixed len maxi, till for cur window mp.size() <= k i.e it's a valid window: so by inc window size: we might get a longer substring.

*/


// TC: O(n)*log(n), SC:O(256)
int kDistinctChars(int k, string &s)
{
    int n = s.size();
    int si = 0, ei = 0, maxi = 0;

    map<char,int> mp; 

    while(ei < n) {
        // update cur window
        mp[s[ei]]++;

        /* window invalid: dec len only if cur window contains 
         more than k distinct char */
        if(mp.size() > k) {
            if(mp[s[si]] == 1) mp.erase(s[si]);
            else mp[s[si]]--;

            si++;
        }


        // update maxi: if valid
        if(mp.size() <= k) maxi = max(maxi, ei-si+1);

        // inc window size
        ei++;
    }

    return maxi;
}
