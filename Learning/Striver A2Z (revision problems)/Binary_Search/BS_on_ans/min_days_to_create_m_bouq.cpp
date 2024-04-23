#include<bits/stdc++.h>
using namespace std; 

class Solution {
public:
    /*  
    DOUBT: for min value of mid: are we always creating == m bouq
    and not >= m bouq, bcz # bouq we create depends on the arrangement of if 'k' consecutive flowers bloom or not 
    */
   
    int check(int d, vector<int> &bd, int m, int k) {
        // sweeping type bs on ans
        int bouq_cnt = 0, cur_bouq_flower_cnt = 0;

        for(int i = 0; i < bd.size(); i++) {
            if(bd[i] <= d) {
                // current flower has bloomed
                // so include it in bouq
                cur_bouq_flower_cnt++;

                if(cur_bouq_flower_cnt == k) {
                    bouq_cnt++;
                    cur_bouq_flower_cnt = 0;
                }
            }
            else {
                // so we reset # flowers in cur bouq bcz unless we take consecutive flowers we cannot create a bouq
                cur_bouq_flower_cnt = 0;
            }
        }

        return (bouq_cnt >= m);
    }

    int minDays(vector<int>& bloomDay, int m, int k) {
        // till minBloomDay no flower bloom
        // till max BloomDay all bloom: so if can create 'm' bouq then we create
        
        int lo = 1e9 + 1, hi = 0, ans = -1;

        for(int i = 0; i < bloomDay.size(); i++) {
            hi = max(hi, bloomDay[i]);
            lo = min(lo, bloomDay[i]);
        }

        /*
            check[] is based on what the check fn does.
            so if in mid days we can create >= m bouq, then
            save ans and search for smaller mid value.

            so check[]: ..0001111..
        */
        while(lo <= hi) {
            int mid = lo + (hi-lo)/2;

            if(check(mid, bloomDay, m, k)) {
                ans = mid;
                hi = mid-1;
            }
            else {
                lo = mid+1;
            }
        }

        return ans;
    }
};