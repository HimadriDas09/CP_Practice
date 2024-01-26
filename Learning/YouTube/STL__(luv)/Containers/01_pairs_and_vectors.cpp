#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define int long long

const int MOD = 1e9 + 7;
const int INF = LLONG_MAX >> 1;

void printVector(vector<int> &v) { // creating a reference of passed vector in v
    // v.size() -> O(1)
    cout << "size: " << v.size() << endl;
    for(int i = 0; i < v.size(); i++) cout << v[i] << " ";
    cout << endl;

    v.push_back(100);
}

signed main()
{
    ios::sync_with_stdio(false); cin.tie(NULL);

    pair<int,string> p; // pair creation

    // pair initialization
    p = make_pair(1, "abc"); // m1

    p = {2, "def"}; // m2


    // pair<int,string> p2 = p; // pass by value 
    pair<int,string> p2 = p; // pass by ref
    p2.first = 3;

    // cout << p.first << " " << p.second << endl;

    // taking input

    // cin >> p.first >> p.second; 
    // cout << p.first << " " <<  p.second;


    // vectors: size is dynamic in nature

    int n;
    vector<int> v; // 0 sized vector define
    vector<int> v2(10); // 10 sized vector with all values == 0(by default)
    // but still it's dynamic in nature bcz we can push_back elem 
    v2.push_back(11);
    printVector(v2);

    // NOTE: even though I called the printVector(v2): it didn't executed it till i entered n and all n values

    // cin >> n;
    // for(int i = 0; i < n; i++) {
    //     int x;
    //     cin >> x;
    //     v.push_back(x); // O(1)
    // }

    // printVector(v);


    vector<int> v3(10, 13); // currently 10 sized with all elem 13
    printVector(v3);


    v3.pop_back(); // O(1): takes out the last value: based on it size changes
    printVector(v3);

    vector<int> copiedVector = v2; // O(n): creating a new vector and copying all elem of v2 in it's copy
    copiedVector.push_back(5);
    printVector(copiedVector);
    printVector(copiedVector);
    printVector(v2);

    return 0;
}