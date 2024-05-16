#include<bits/stdc++.h>
using namespace std;

// to min(maxima): divide into multiple subarrays such that 
// each subarray has max sum ( <= x)
// if this is possible with students_cnt <= m : return true
// even for student_cnt < m: we could've distributed more by not combining books to reach <= x pages to be give to each student.

bool check(int x, vector<int> &arr, int m) {
    // x is max no of pages that we can assign to a student
    // check if we can give books to all students or not.
    int n = arr.size();

    int students_cnt = 0;
    int pages = 0;

    for(int i = 0; i < n; i++) {
        if(pages + arr[i] <= x) {
            // add books
            pages += arr[i];

            if(pages == x || i == n-1) {
                students_cnt++;
                pages = 0;
                
                if(students_cnt > m) return false;
            }
        }
        else {
            // discard the last book
            students_cnt++;
            pages = arr[i];
            
            if(i == n-1) {
                students_cnt++;
            }

            if(students_cnt > m || pages > x) return false;
        }
    }

    return students_cnt <= m; 
    /* if students_cnt <= m: then we can even dec subarray size
    so that all students can get books, but if students_cnt > m:
    it means even with maintaining max subarr sum: we could supply
    books to more students: so couldn't distribute all books
    with max x pages to allocate  */
}

int findPages(vector<int>& arr, int n, int m) {
    // Write your code here.
    if(n < m) return -1;


    int lo = 2*1e9, hi = 0, ans = -1;

    for(int i = 0; i < n; i++) {
        lo  = min(lo, arr[i]);
        hi += arr[i];
    } 

    // since it's minimising the maxima: so check[]: ..000111..
    while(lo <= hi) {
        int mid = lo + (hi-lo)/2;

        if(check(mid, arr, m)) {
            // save ans and check left
            ans = mid; 
            hi =  mid-1;
        }
        else {
            lo = mid+1;
        }
    }

    return ans;
}