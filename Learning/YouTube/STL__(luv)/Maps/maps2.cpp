/*
    Difference between map and unordered_map

    1. Inbuilt Implementation:
        - Hash tables are used unlike Red Black Trees in maps

    2. Time Complexity:
        - avg: O(1) for access,deletion,insertion

    3. Valid key Datatypes:
        - eg: unordered_map<pair<int,int>, string> mp; ERROR, but works in case of map
            - Bcz internally unordered_map works by calculating hash value of key, and map works based on comparison.

            - Which ever Datatype doesn't have a hash function: cannot be used as keys in unordered_map: i.e complex data types. So for them use maps.

            - data type that have a hash value: basic data type: int,long long, double, float, string, bool.

    NOTE: multimap<,> => same as map But mp[same name key] => this doesn't update the pre key value But create a new pair
        - But if I need to store different value for same key, Rather than using multimap, I'd use map<int,vector<string>> mp
*/


#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define int long long

const int MOD = 1e9 + 7;
const int INF = LLONG_MAX >> 1;

void print(unordered_map<int,string> &mp) {
    // unordred_map: printed in any random order

    cout << mp.size() << endl;
    for(auto &it: mp) {
        cout << it.first << " " << it.second << endl;
    }
}


signed main()
{
    ios::sync_with_stdio(false); cin.tie(NULL);

    unordered_map<int,string> mp;
    mp[1] = "abc"; // avg TC: O(1): for insertion, access 
    // with internal collision in hash table: TC might increase 
    mp[6] = "zyx";
    mp[2] = "def";
    mp[3] = "ghi";
    mp[5] = "klm";

    print(mp);

    return 0;
}