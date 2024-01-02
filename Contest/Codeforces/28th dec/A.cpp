#include<bits/stdc++.h>
using namespace std;

unordered_map<int,int> mp;

int main()
{
    int t,a,b,c;
    cin >> t;
    while(t--) {
        cin >> a;
        mp[a]++;
        cin >> b;
        mp[b]++;
        cin >> c;
        mp[c]++;

        // iterate the map
        for(auto it:mp){
            if(it.second != 2) cout << it.first << endl;
        } 
        mp.clear();       
    }
    return 0;
}