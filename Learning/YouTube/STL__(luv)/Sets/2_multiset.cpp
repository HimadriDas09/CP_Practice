/*
    THEORY: 

    multiset

    1. same value can be stored multiple times.
        - Rest all: same as sets i.e store values in sorted order.

    2. all TC: O(log(n)) bcz of Red Black trees internally.

    3. has same function has "Priority Queues".

    4. to remove an element: user ms.erase(iterator of the elem) : to only remove that elem whose iterator we've passed. so even if multiple elems with same val: only the elem present earlier will be deleted.
        - Whereas ms.erase(val): delete all the vals present in multiset.

*/

#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define int long long

const int MOD = 1e9 + 7;
const int INF = LLONG_MAX >> 1;

void print(multiset<string> &ms) {
    for(auto val: ms) {
        cout << val << " ";
    }
    cout << endl;
}

signed main()
{
    ios::sync_with_stdio(false); cin.tie(NULL);

    multiset<string> ms;
    ms.insert("def");
    ms.insert("khi");
    ms.insert("abc");
    ms.insert("abc");


    // auto it = ms.find("abc"); // returns the iterator that is encountered first && ms.erase(it): will delete the elem whose iterator we've passed.

    // if(it != ms.end()) {
    //     ms.erase(it); // .erase(iterator)
    // }

    ms.erase("abc"); // will delete all the elements which are "abc" even if there are multiple of them.
        // bcz it keeps on finding iterator of "abc" until there is not iterator of "abc" left.

    print(ms);

    return 0;
}