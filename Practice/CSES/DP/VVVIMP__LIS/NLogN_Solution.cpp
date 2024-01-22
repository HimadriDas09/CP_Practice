#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define int long long

const int MOD = 1e9 + 7;
const int INF = LLONG_MAX >> 1;

int n;
int arr[200000];

void solve() {
    // maintain array to store: all merged LIS: for every IS ending at ind i
    vector<int> mergedLIS;

    for(int i = 0; i < n; i++) {
        // for every elem: find where will the ith elem fit in the merged IS: can use BS: bcz search space is increasing

        // lowerBound Code: find ind such whose value is >= target
        int size = mergedLIS.size();
            
        // searching for index at which we put ith elem
        int tar = arr[i];
        int lo = 0, hi = size-1, ans = -1; 
        while(lo <= hi) {
            // ...000001111...
            int mid = (lo+hi)/2;
            if(mergedLIS[mid] >= tar) {
                // valid but still search left
                ans = mid;
                hi = mid-1;
            }
            else {
                // search right for greater val
                lo = mid+1;
            }
        }
        if(ans != -1) mergedLIS[ans] = tar;
        else {
            // elem at last pos
            mergedLIS.push_back(tar);
        }
        
    }

    cout << mergedLIS.size() << endl;
}

signed main()
{
    ios::sync_with_stdio(false); cin.tie(NULL);

    cin >> n;
    for(int i = 0; i < n; i++) cin >> arr[i];
    solve();

    return 0;
}