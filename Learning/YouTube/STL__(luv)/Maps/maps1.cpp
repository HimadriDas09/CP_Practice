// THEORY:
/* Basics of MAP:
    - in normal map: pair is sorted based on key value. 
        - Behind the scene, it is implemented using a Data Structure called "Red Black Trees".
    - If (key = String), then {sorted order == they will appear in lexographical order i.e dictionary order}

    - How ar maps stored in memory ?
        - each elem is a pair<,> && is stored at random location, each connected with links
        - So, to iterate via iterators => we cannot do it = it+1 i.e next mem location. But we can do it++.

    - Again enter a pair with same key-name => just the value of the key is updated && not another new pair is created.

    - TC: searching : O(logN), insertion: O(logN), find: O(logN), erase: O(logN)

    - TC => also depends on the type of keys
        - Whenever we're inserting a new <key,val>, it's comparison with the existing keys takes place.
            => Total = Log(N) comparisons occurs and based on that the key is put to it's correct place.   

        - <string,string> : log(n) comparisons among keys occur, N = len of map && to do each comparison i.e string: O(string.size())
            => total : O(log(n))*(str.size())
            => For bigger Strings: TC would matter.
*/

#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define int long long

const int MOD = 1e9 + 7;
const int INF = LLONG_MAX >> 1;

void print(map<int,string> &m) {

    // TC: to access each value in map: is O(log(n))
    cout << m.size() << endl;
    for(auto &pr : m) { // &pr so that copy of the pair is not created
        cout << pr.first << " " << pr.second << endl;
    }
    // above loop TC: (n)*log(n)
}

signed main()
{
    ios::sync_with_stdio(false); cin.tie(NULL);

    map<int,string> m;
    // insert elem in map

    m[1] = "abc"; // TC of insertion: O(log(n)), n = cur no of elem in map
    m[5] = "def";
    m[3] = "ghi";
    m[6]; // NOTE: O(log(n)) to determine pos of where it will be present, value = "" by default and if value type = int, default would've been 0
    // i.e empty value of type of value

    m.insert({4, "ghi"});
    m[5] = "five";

    // print elem of map

    // map<int,string> :: iterator it;
    // for(it = m.begin(); it != m.end(); it++) {
    //     cout << (*it).first << " " << (*it).second << endl;
    // }   


    // NOTE: Find and Erase:
        // 1) m.find(key_name) returns an iterator of pair with key = key_name && if the key is not found, it returns m.end()

        // 2) m.erase(key_name) OR m.erase(iterator value)
            // make sure that the pair exists, else pair rep m.end() which is not an existing pair
                // so segmentation fault
    
    auto it = m.find(7); // O(log(n))
    // if(it == m.end()) {
    //     cout << "No value" << endl;
    // }
    // else {
    //     cout << (*it).first << " " << (*it).second << endl;
    // }

    // m.erase(3); // {3, ghi} is erased from map
    if(it != m.end()) 
        m.erase(it);

    m.clear(); // removes all elem from map => is common in vectors,sets,map
    print(m);

    return 0;
}