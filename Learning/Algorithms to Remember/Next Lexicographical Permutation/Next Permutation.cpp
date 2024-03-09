#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define int long long

const int MOD = 1e9 + 7;
const int INF = LLONG_MAX >> 1;


// Approach:
/*
    1. For Next permutation i.e next order of nos in dictionary order. Fix the longest possible prefix and permute the suffix to get the just greater permutation.

    2. For Next greater permutation i.e at some ith pos we need to place a number greater than it. And that greater number should appear at the right of ith elem: then only we're fixing the prefix and permuting the suffix. 

    3. So moving from right to left. At the first dip i.e right of ith pos there is a number greater than elem i. Now at ith pos: put the number just greater than ith elem i.e (either Binary Search on sorted arrangement of traversed elem i.e n*log(n) + log(n)) OR (since right to left in Increasing order so using a Linear Search find elem just greater than elem i) and swap their posn: now prefix + ith elem are at correct position.

    4. then after ith pos: find the smallest arrangement i.e sorting (n*log(n)) OR (since right to left in inc order so just reverse the arrangement)
*/

void nextPermutation(vector<int>& nums) {
    int n = nums.size();
    int i = -1;

    for(i = n-2; i >= 0; i--) {
        if(nums[i] < nums[i+1]) {
            // at ith elem we've the 1st dip
            break;
        }
    }

    if(i == -1) {
        // no dip encountered: i.e nums is lexicographically largest 
            // just reverse it
        reverse(nums.begin(), nums.end());
    }
    else {
        // swap ith elem with just greater elem than it
            // moving from right: bcz right to left is sorted space
        for(int j = n-1; j > i; j--) {
            if(nums[j] > nums[i]) {
                swap(nums[j], nums[i]);
                break;
            }
        }

        // now from (i+1)th elem to last elem: we need to smallest arrangement
            // since right to left is sorted to just reverse
        reverse(nums.begin()+i+1, nums.end());
    }
}



signed main()
{
    ios::sync_with_stdio(false); cin.tie(NULL);



    return 0;
}