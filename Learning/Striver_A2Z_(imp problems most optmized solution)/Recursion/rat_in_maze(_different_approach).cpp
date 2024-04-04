#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define int long long

const int MOD = 1e9 + 7;
const int INF = LLONG_MAX >> 1;

signed main()
{
    ios::sync_with_stdio(false); cin.tie(NULL);



    return 0;
}

// m2: you can make changes to the original mat: to mark if you've visited it or not => for a smaller time complexity i.e similar to "WORD SEARCH"

// m1
void deleteCell(int i, int j,  map<int, set<int>> &mp) {
    // if row contains more than 1 columns: then delete that specific col of the row
    if(mp[i].size() > 1) {
        auto &st = mp[i];
        st.erase(j);
    }   
    else {
        mp.erase(i);
    }
    // else delete the whole elem of mp
}

void addCell(int i, int j,  map<int, set<int>> &mp) {
    // even if row exists or not: nothing is going to be overwritten.
    mp[i].insert(j);
}

bool cellVisited(int i, int j, map<int, set<int>> &mp) {
    if(mp.find(i) != mp.end()) {
        // row visited 

        // check column
        auto &st = mp[i];

        if(st.find(j) != st.end()) {
            // col visited
            return true;
        }
        return false;
    }
    return false;
}

void exploreAllPaths(int i, int j, string &cur_path, vector<vector<int>> &mat, map<int, set<int>> &mp, vector<string> &ans) {
    int n = mat.size();

    // bc
    if(i == n-1 && j == n-1) {
        // ans path to ans && unmark the destination cell
        deleteCell(i,j,mp);
        ans.push_back(cur_path);
        return;
    } 

    // check which cells can you go to before going
        // out of bound, 0/1, if visited or not

    // up
    if(i-1 >= 0 && mat[i-1][j] != 0 && !cellVisited(i-1, j, mp)) {
        // can visit

        cur_path += 'U';
        addCell(i-1,j,mp);

        exploreAllPaths(i-1,j,cur_path,mat,mp,ans);

        deleteCell(i-1,j,mp);
        cur_path.pop_back();
    }

    // down
    if(i+1 < n && mat[i+1][j] != 0 && !cellVisited(i+1, j, mp)) {
        // can visit

        cur_path += 'D';
        addCell(i+1,j,mp);

        exploreAllPaths(i+1,j,cur_path,mat,mp,ans);

        deleteCell(i+1,j,mp);
        cur_path.pop_back();
    }

    // left
    if(j-1 >= 0 && mat[i][j-1] != 0 && !cellVisited(i, j-1, mp)) {
        // can visit

        cur_path += 'L';
        addCell(i,j-1,mp);

        exploreAllPaths(i,j-1,cur_path,mat,mp,ans);

        deleteCell(i,j-1,mp);
        cur_path.pop_back();
    }

    // right
    if(j+1 < n && mat[i][j+1] != 0 && !cellVisited(i, j+1, mp)) {
        // can visit

        cur_path += 'R';
        addCell(i,j+1,mp);

        exploreAllPaths(i,j+1,cur_path,mat,mp,ans);

        deleteCell(i,j+1,mp);
        cur_path.pop_back();
    }

    return;
}

vector<string> ratMaze(vector<vector<int>> &mat) {
    vector<string> ans;

    map<int, set<int>> mp; // row, <set of columns> : to rep it cell visited or not

    string cur_path = "";
    int n = mat.size();
    int i = 0, j = 0;

    // mark the 0,0 cell as visted
    addCell(0,0,mp);
    exploreAllPaths(i, j, cur_path, mat, mp, ans);


    return ans;
}