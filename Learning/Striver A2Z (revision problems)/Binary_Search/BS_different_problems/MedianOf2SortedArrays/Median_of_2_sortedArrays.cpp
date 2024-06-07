#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size(), n2 = nums2.size();
        // find the no of elem that should be present in the left side of the symmetry = cnt;
        int cnt = (n1 + n2 + 1)/2;
        // there are multiple ways to place cnt no of elem in the left side -> among which one is valid configuration -> find it using binary search on (# elem present in smaller array)
        
        // NOTE: by default we're considering nums1 to be the smaller array && therefore applying BS on nums1

        if(n2 < n1) {
            // replace the references such that we work on the smaller array
            return findMedianSortedArrays(nums2, nums1);
        }

        /* 
        'lo' is min elem to pick from arr1 for left partion of the array, 'hi' is max elem to pick from arr1 for left partition of the array.

        if lo == 0 then we've to pick 'cnt' elem from arr2 BUT arr2 should've 'cnt' no of elem. if arr2.size() > cnt then we pick 'cnt' elem else we pick arr2.size() elem from arr2 i.e we pick either 0 or (cnt-arr2.size()) from arr1 i.e max of them.

        similary hi = pick min(cnt, nums1.size()) from arr1 -> case when arr1 doesn't have 'cnt' elem.
         */
        int lo = 0 > cnt-nums2.size() ? 0: cnt-nums2.size();
        int hi = cnt < nums1.size() ? cnt : nums1.size();

        double ans;

        while(lo <= hi) {
            int mid1 = lo + (hi-lo)/2;
            int mid2 = cnt-mid1;
            // mid1: #elem from nums1, mid2: #elem from nums2 for left side of symmetry.

            int l1 = mid1 > 0 ? nums1[mid1-1] : INT_MIN;
            int l2 = mid2 > 0 ? nums2[mid2-1] : INT_MIN;
            int r1 = mid1 < nums1.size() ? nums1[mid1] : INT_MAX;
            int r2 = mid2 < nums2.size() ? nums2[mid2] : INT_MAX;

            if(l1 <= r2 && l2 <= r1) {
                // this is the ans
                if((n1 + n2) % 2 == 0) {
                    ans = (double)(((double)(max(l1, l2) + min(r1, r2)))/(double)2);
                }
                else {
                    ans = (double)(max(l1,l2));
                }
                break;
            }
            else if(l1 > r2) {
                // remove greater elem from the smaller array 
                    // i.e take less elem for left
                hi = mid1-1;
            }
            else if(l2 > r1){
                // remove greater elem from larger array i.e inc greater elem from smaller array
                    // i.e inc #elem for left
                lo = mid1+1;
            }
        }

        // median(even len) = max(l1, l2) + min(r1, r2) / 2
        // median(odd len) = max(l1, l2)

        return ans;
    }
};