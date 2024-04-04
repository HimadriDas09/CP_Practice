
#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define int long long

const int MOD = 1e9 + 7;
const int INF = LLONG_MAX >> 1;



signed main()
{
    ios::sync_with_stdio(false); cin.tie(NULL);

    map<pair<int,int>, int> m;

    pair<int,int> p1, p2;
    p1 = {1,2}, p2 = {1, 1};

    cout << (p1 < p2); // comparison based on the first value, if first value of both pair is same then comparison based on second value. So in map they are inserted in this order only.


    map <pair<string,string>, vector<int>> mp; // <firstname, lastname>,<marks[]>
    int n;
    cin >> n;

    for(int i = 0; i < n; ++i) {
        string firstname,lastname;
        int cnt;

        cin >> firstname >> lastname >> cnt;

        for(int j = 0; j < cnt; ++j) {
            int val;
            cin >> val;

            mp[{firstname, lastname}].push_back(val); // mp[{f,l}] : consider this to be a vector
        }
    }

    // printing the above container
        // just use ref bcz we're just printing

    for(auto &pr: mp) { // pr rep a pair of the mp: so rather use it's reference i.e &pr
        auto &full_name = pr.first;
        auto &list = pr.second;

        cout << full_name.first << full_name.second << endl;
        cout << list.size() << endl;

        for(auto &elem : list) {
            cout << elem << " ";
        }
        cout << endl;
    }
    

    return 0;
}