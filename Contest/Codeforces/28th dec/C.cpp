#include<bits/stdc++.h>
using namespace std;
using lli = long long;

int arr[1000000];

int main()
{
    int t;
    cin >> t;

    while(t--) {
        int n;
        cin >> n;
        for(int i = 0; i < n; i++) cin >> arr[i];

        lli tot_sum = 0;
        for(int i = 0; i < n; i++) tot_sum += arr[i];

        // if tot_sum is a perfect square then as is "YES" else "NO"
        double sq_root = sqrt(tot_sum);

        if(floor(sq_root) == sq_root) {
            // it's a perfect square 
            cout << "YES" << endl;
        }
        else {
            // not a perfect square
            cout << "NO" << endl;
        }
    }

    return 0;
}