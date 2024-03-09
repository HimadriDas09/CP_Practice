/*
    Theory: sets

    1. set: stored according to sorted order.
    2. TC: insertion, access, find(), erase(): O(log(n)).
        - s.erase() takes either of 2 values: either elem val/ iterator of elem.
    3. same element inserted > once: is present once only in set.
    4. uses Red Black Trees Internally.

    unordered_set
        - ideal when order doesn't matter

    1. all TC: O(1)
    2. uses hash table internally.
    3. cannot keep containers other than basic data types(int,double,float,char,bool): bcz their hash fns are not already defined.

*/


#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define int long long

const int MOD = 1e9 + 7;
const int INF = LLONG_MAX >> 1;

void print(set<string> &s) {
    // M1
    for(auto val: s) { // val rep value
        cout << val << " ";
    }
    cout << endl;
    // M2
    for(auto it = s.begin(); it != s.end(); it++) { // it rep addres
        cout << *it << " ";
    }
    cout << endl;
}

signed main()
{
    ios::sync_with_stdio(false); cin.tie(NULL);

    set<string> s; // can contain any container. eg: map, set, string, vector etc
    s.insert("ghi");
    s.insert("abc");
    s.insert("def");

    // access elem: using find && cannot use st[elem] unlike maps
        // find() returns an iterator
            // if not exist returns it = s.end()

    auto it = s.find("abc"); 

    if(it != s.end()) {
        // cout << *(it) << endl;
        s.erase(it); // taking iterator
    }

    s.erase("def"); // taking value

    print(s);


    return 0;
}