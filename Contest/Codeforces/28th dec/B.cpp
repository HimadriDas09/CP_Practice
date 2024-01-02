#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;

    vector<vector<char>> mat(3, vector<char> (3));
    unordered_set<char> st;

    while(t--) {
        /* for each tc: a 3*3 matrix is required */
        for(int i = 0; i < 3; i++) {
            for(int j = 0; j < 3; j++) cin >> mat[i][j];
        }

        for(int r = 0; r < 3; r++) {
            st.insert('A');
            st.insert('B');
            st.insert('C');
            bool is_absent = false;

            for(int c = 0; c < 3; c++) {
                if(mat[r][c] != '?') st.erase(mat[r][c]);
                else {
                    // other than that remove other characters from set
                    is_absent = true;
                }
            }

            if(is_absent) {
                for(auto &it : st) cout << it << endl;
            }
            st.clear();
        }
    }

    return 0;
}