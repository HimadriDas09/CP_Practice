#include<bits/stdc++.h>
using namespace std;

/*
Explanation:

- does always choosing the pile with smallest bananas help i.e
using priority queue or sorting the array help ??

    - no bcz, we're choosing a pile and eating bananas and not combining bananas of multiple piles and eating 'k' of them in an hr.

- so in whichever order we eat, and whichever pile we choose in between: based on fixed k, it'll always take fixed no of hrs.

- since we need to minimize the value of 'k'. so what could be the probable valid values of 'k': i.e if we eat at rate of k: it takes <= h hrs. why <= h and not == h: bcz for a greater 'k', it'll take lesser hrs.

- so min value of k = 1 and max value of k(since we're to choose a pile and eat at rate of k: so max value if max ban in a pile).

- now perform bs on ans on this search space.

*/

class Solution {
public:
    int check(int k, vector<int> &piles, int h) {

        for(int i = 0; i < piles.size(); i++) {
            int hrs = piles[i]/k;

            if(hrs*k < piles[i]) hrs++;

            h -= hrs;
        }

        return (h >= 0);
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int n = piles.size();
        int lo = 1, hi = 0, ans;

        for(int i = 0; i < n; i++) {
            hi = max(hi, piles[i]);
        }

        // check[]: ..00001111...

        while(lo <= hi) {
            int mid = lo + (hi-lo)/2;

            if(check(mid, piles, h)) {
                // save ans and go left
                ans = mid;
                hi = mid-1;
            }
            else {
                // go right
                lo = mid+1;
            }
        }

        return ans;
    }
};