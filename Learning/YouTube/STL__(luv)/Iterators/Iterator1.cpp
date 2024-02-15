#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define int long long

const int MOD = 1e9 + 7;
const int INF = LLONG_MAX >> 1;

signed main()
{
    ios::sync_with_stdio(false); cin.tie(NULL);

    vector<int> v = {1,2,3,4,5,6};
    for(int i = 0; i < v.size(); i++) cout << v[i] << " ";
    cout << endl;

    // Iterators: pointers like structures
    // syntax to declare an iterator
    vector<int> :: iterator it = v.begin(); 
    // v.begin() points to address of 0th location of v -> to access value deference it
    // v.end() points to next address of last element of v

    cout << *(it+1) << endl;

    // iterate over all elem of container
    for(it = v.begin(); it != v.end(); it++) cout << *it << " ";
    cout << endl;


    // NOTE: 
    // 1. it++ and it = it+1 -> in case of vectors both are same, bcz vectors are continuous mem locations, so it points to next cell in both cases

    // But other containers like map,set are not continous mem location, so do it++ -> points to next iterator


    vector<pair<int,int>> vp = {{1,2}, {2,3}, {3,4}};
    vector<pair<int,int>> :: iterator it2;

    for(it2 = vp.begin(); it2 != vp.end(); it2++) {
        cout << (*it2).first << " " << (*it2).second << endl;
    }

    // Instead of (*it).first we can use it->first
    for(it2 = vp.begin(); it2 != vp.end(); it2++){
        cout << it2->first << " " << it2->second << endl;
    }


    return 0;
}