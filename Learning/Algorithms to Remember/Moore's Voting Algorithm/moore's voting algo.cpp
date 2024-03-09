#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define int long long

const int MOD = 1e9 + 7;
const int INF = LLONG_MAX >> 1;

int majorityElement(vector<int>& nums) {
    // Moore's Voting Algorithm: O(2n)

    int n = nums.size();
    int elem = nums[0], cnt = 0; // size > 0 always

    for(int i = 0; i < n; i++) {

        if(cnt == 0) {
            // start cur subarray from this elem
            elem = nums[i];
            cnt = 1;
        }
        else if(elem == nums[i]) cnt++;
        else cnt--;

    }

    // elem: always contains the majority elem if there is one
        // so check if this is the majority elem or not.
    cnt = 0;
    for(int i = 0; i < n; i++) {
        if(nums[i] == elem) cnt++;
    }

    if(cnt > n/2) return elem;
    return -1;
}

signed main()
{
    ios::sync_with_stdio(false); cin.tie(NULL);



    return 0;
}
