#include<bits/stdc++.h>
using namespace std;

// with min no of operations: to get the largest string is to keep to char that appears max no of times = constant && change rest of the characters to this characters.

// so in current window we need to find the max frequency.
    // since uppercase: hash[26] and do a O(26) for search of maxi.

// M1) TC: O(2n), SC: O(26)

int characterReplacement(string s, int k) {
    int n = s.size();
    int si = 0, ei = 0, len = 0;
    int maxi = 0; // max freq of a char in cur window

    // only uppercase char are present 
    vector<int> hash(26, 0); // char(s[i]-'A') : cnt

    while(ei < n) {
        // update cur window
        hash[s[ei]-'A']++;
        maxi = max(maxi, hash[s[ei] - 'A']);

        // invalid window: make valid
            // i.e cur window len - max freq > k
        while(ei-si+1 - maxi > k) {
            hash[s[si] - 'A']--;
            maxi = 0;

            // might need to update maxi
            for(int i = 0; i < 26; i++){
                maxi = max(maxi, hash[i]);
            }
            si++;
        }

        // update len (here: valid window)
        len = max(len, ei-si+1);

        // inc window len
        ei++;
    }

    return len;
}

// Optimization 1 and 2) 

/*
Multiple observation:

- inner while loop: while(ei-si+1 - maxi > k)

    - When did we enter the inner while loop ??

        - for prev valid substring: 'len' got update and then ei++, i.e 1 extra char got added and substr became invalid. {so we decide to do si++ till substr is valid}

        - 2 things: 
            - 1) since we need a greater len substr: so dec window len beyound 'maxLen' makes no sense. so if cur string is invalid. just remove the char at si from window once and window len remains const i.e maxLen.

            - 2) Now as long as maxLen sized window is invalid. we keep it at this size only and when it's valid, we keep on inc the window.

                - Now with sliding of fixed sized window of len 'maxLen': do we need to update maxi ?? 

                - if we exclude s[si] then either maxi rem same/ dec: (both case: invalid window(since end-st+1 - maxi > k): which is required to be decrease: which we won't to consider longer substring)

                - so don't update maxi : if invalid window

*/

// MOST OPTIMIZED: 

// TC: O(n), SC: O(26)
int characterReplacement(string s, int k) {
    int n = s.size();
    int si = 0, ei = 0, len = 0;
    int maxi = 0; // max freq of a char in cur window

    // only uppercase char are present 
    vector<int> hash(26, 0); // char(s[i]-'A') : cnt

    while(ei < n) {
        // update cur window
        hash[s[ei]-'A']++;
        maxi = max(maxi, hash[s[ei] - 'A']);

        // invalid window: make valid
            // i.e cur window len - max freq > k
        if(ei-si+1 - maxi > k) {
            hash[s[si] - 'A']--;
            si++;
        }

        // update len (here: valid window)
        len = max(len, ei-si+1);

        // inc window len
        ei++;
    }

    return len;
}