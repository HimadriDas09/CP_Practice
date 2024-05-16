#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define int long long

const int MOD = 1e9 + 7;
const int INF = LLONG_MAX >> 1;


bool check(long double x, vector<int> &arr, int k) {
	int n = arr.size();
	long long placed_cnt = 0;
	
	for(int i = 0; i < n-1; i++) {
		long double dist = arr[i+1]-arr[i];
		long double multiple = dist/x;

		if((int)multiple == multiple) {
			placed_cnt += (dist/x)-1;
		}
		else {
			placed_cnt += floor(dist/x);
		}
		
	}

	return placed_cnt <= k; // i.e rem stations could be put later in x axis by maintaining dist 'x' 
	// so we return 1, but if placed_cnt > k: to maintain 'x' we had to put more, rather inc value of x 
	// i.e inc value of 'x' i.e go right i.e return 0;
}


double minimiseMaxDistance(vector<int> &arr, int k){
	int n = arr.size();
	long double lo = 0, hi;
	
	int maxDist = arr[0]-0;
	// find hi: i.e max distance between adjacent station
	for(int i = 0; i < n-1; i++) {
		maxDist = max(maxDist, arr[i+1]-arr[i]);
	}
	hi = maxDist;

	long double EPS = 1e-8;// bcz precision of 1e-6 is reqd

	// check[]: since min(max) so ...00001111..
	while(abs(hi-lo) >= EPS) {

		long double mid = (lo + hi)/2;

		if(check(mid, arr, k)) {
			hi = mid;
		}
		else {
			lo = mid;
		}
	}

	long double ans = (lo + hi)/2;

	return ans;
}



signed main()
{
    ios::sync_with_stdio(false); cin.tie(NULL);

    vector<int> arr = {1,11};
    int k = 2;

    cout << minimiseMaxDistance(arr,k) << endl;

    return 0;
}