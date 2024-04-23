#include<bits/stdc++.h>
using namespace std;

// standard BS on answers

// checking for if this is probable min distance bet 2 cons
int check(int d, vector<int> &stalls, int k) {
    /* check if atleast 'd' distance i.e >= d distance can be 
    maintained between 2 consecutive stalls or not. bcz if 
    exactly 'd' then d is save and if >= d then we're also going
    right for searching */

    int cows_placed = 1; // at stall[0]
    int last_ind = 0;

    for(int i = 0; i < stalls.size(); i++) {
        if(stalls[i] - stalls[last_ind] >= d) {
            // place cow at i
            cows_placed++;
            last_ind = i;
        }
    }

    return cows_placed >= k;
}
int aggressiveCows(vector<int> &stalls, int k)
{
    // BS on answers: bcz max(min)
    int n = stalls.size();
    sort(stalls.begin(), stalls.end()); 
    /* so that for checking a probabale ans: 
    we can know if min distance between 2 stalls 
    i.e x i.e what we're trying to maintain is maintained or not */

    int lo = 0; // placing 2 cows at same stall but low could be min distance bet 2 consequtive stalls
    int hi = stalls[n-1] - stalls[0], ans;

    while(lo <= hi){
        int mid = lo + (hi-lo)/2;

        // based on what the check fn returns 
            // determine the check array
            // if probable ans: so check return 1 else 0
            // and higher mid value: less probable
            // so check[]: ...1111100000...

        if(check(mid, stalls, k)) {
            ans = mid;
            lo = mid+1;
        }
        else {
            hi = mid-1;
        }
    }
    return ans;

}