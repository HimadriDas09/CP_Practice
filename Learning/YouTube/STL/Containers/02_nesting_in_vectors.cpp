#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define int long long

const int MOD = 1e9 + 7;
const int INF = LLONG_MAX >> 1;

void printVec(vector<int> &v) {
    cout << "size: " << v.size() << endl;
    for(int i = 0; i < v.size(); i++) {
        // v[i]: pair<int,int>
        // cout << v[i].first << " " << v[i].second << endl;
        cout << v[i] << endl;
    }
}

void printVec2D(vector<vector<int>> &v) {
    // for each row print all the cols
    for(int r = 0; r < v.size(); r++) {
        // v[i]: rep a vector
        for(int c = 0; c < v[r].size(); c++) {
            cout << v[r][c] << " ";
        }
        cout << endl;
    }
}

signed main()
{
    ios::sync_with_stdio(false); cin.tie(NULL);
    cout << endl;

    /*-------------------------------------------------------------------------*/

    // Vector of pairs > IMP for cp

    /*    
    vector<pair<int,int>> v;

    int n;
    cin >> n;

    for(int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        v.push_back({x,y});
    }

    printVec(v);

    */

   /*----------------------------------------------------------------------*/
    // Array of Vectors

    /*
    int N;
    cin >> N;

    vector<int> v[N]; 
    // array creation: int a[size]: so data type of each location in arr is a vector<int> of size 0

    // like a 2D vector: but no of rows is fixed i.e no of vectors
        // to make it dynamic: define vector<vector<int>> 

    for(int i = 0; i < N; i++) {
        // v[i] rep a vector of 0 size
        int n; // size of v[i]
        cin >> n;

        for(int j = 0; j < n; j++) {
            // adding n values to v[i]
            int x;
            cin >> x;
            v[i].push_back(x);
        }

        // printing
        printVec(v[i]);

    }

    */

   /*------------------------------------------------------------------------*/

    // Vector of Vector

    vector<vector<int>> v;

    int n; // size of vector<vector<int>> 
    cin >> n;

    for(int i = 0; i < n; i++) {
        // v[i]: rep a vector
        int size;
        cin >> size;

        vector<int> temp;
        for(int j = 0; j < size; j++) {
            int x;
            cin >> x;
            temp.push_back(x);
        }

        v.push_back(temp);
    }

    printVec2D(v);

    return 0;
}