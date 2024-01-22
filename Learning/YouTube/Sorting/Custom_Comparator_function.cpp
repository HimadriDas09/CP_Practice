#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define int long long

const int MOD = 1e9 + 7;
const int INF = LLONG_MAX >> 1;

// comparator fn: HOW DOES IT WORK ?

// Not inbuilt comparator
// in asc order
bool cmp(int a, int b) {
    if(a > b) return true; // greater no to be in later pos
    return false;
}

// for inbult comparator fn: if you want to SWAP then return FALSE

// 1st no in pair: in inc order
    // 2nd no in pair: in dec order
bool cmp_pair_Extended(pair<int,int> a , pair<int,int> b) {
    if(a.first != b.first) {
        // sort 1st in inc order 
        if(a.first > b.first) return false; // swap (a,b)
        return true;
    }
    else {
        // same first : sort 2nd no in dec order
        if(a.second < b.second) return false; // swap (a,b)
        return true; 
    }
}

// shortcut to write: 
    // in whatever order you need things: return that condition only: 
    //WHY IT WORKS? - when true it won't stop: when false: it'll swap

bool cmp_pair_Shortcut(pair<int,int> a, pair<int,int> b) {
    if(a.first != b.first) {
        // first: sort acc to inc order
        return a.first < b.first;
    }
    // second: sort acc to dec order
    return a.second > b.second;
}

signed main()
{
    ios::sync_with_stdio(false); cin.tie(NULL);

    int n;
    cin >> n;
    vector<pair<int,int>> arr(n);

    for(int i = 0; i < n; i++) cin >> arr[i].first >> arr[i].second;

    // O(n2): sorting logic: remains const: we'll just change the comparator fn

    // for(int i = 0; i < n; i++) {
    //     for(int j = i+1; j < n; j++) {
    //         // every sorting algo: based on some condition: swapping happens
    //         // But we can decide when does swapping happens
    //         if(should_I_swap(arr[i], arr[j])) {
    //             swap(arr[i], arr[j]);
    //         }
    //     }
    //     // end of each itern: largest no is pushed to end: for asc order sorting logic
    // }


    // without comparator fn: in asc order
    // C++ STL: return false from comparator fn if you want to swap, else return true
    sort(arr.begin(), arr.end(), cmp_pair_Shortcut); 

    cout << endl;
    // printing
    for(int i = 0; i < n; i++) {
        cout << arr[i].first << " " << arr[i].second << endl;
    } 

    return 0;
}