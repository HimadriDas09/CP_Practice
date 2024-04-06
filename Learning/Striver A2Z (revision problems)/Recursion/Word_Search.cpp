#include<bits/stdc++.h>
using namespace std;

/*
    Approach and thought process:
    - Recursion to visit all the cells

    1. to mark which cells we've visited in cur path, either we can maintain map<row, set<cols>> OR mark in board only and when we backtrack we revert the change.

    2. rather than maintaining "cur_string" till now, with every character match: recusion(word.substr(1)) and when we backtrack it's same as usual.

    NOTE: string s = "h", s.substr(1) is empty string.
*/
class Solution {
public:
    // from cell(i,j) is there a way to construct rest of word
    int exploreAllPaths(int i, int j, vector<vector<char>> &board, string word) {
        int m = board.size(), n = board[0].size(); // to make sure we stay inside bounds, m = row, n = col

        // bc
        if(word.size() == 0) return 1;


        // SC: 
            // if cur char matches word[0] do word.substr(1) in recursive calls, if don't matches return false. 
            // don't go to (already visited cells, out of bound cells), else explore all the other neighboring cell && if any of them return true: return true;

            // else: i.e can't visit neighboring OR all returned false: so return false

        if(board[i][j] != word[0]) return 0;
        
        // else cur cell matches(so mark it visited) also check if word.substr(1) is empty or not
        if(word.substr(1).size() == 0) return 1;


        char cell_value = board[i][j];
        board[i][j] = '\0';

        int final_ans = 0;

        // up
        if(i-1 >= 0 && board[i-1][j] != '\0') {
            final_ans |= exploreAllPaths(i-1,j, board, word.substr(1));
        }
        // down
        if(i+1 < m && board[i+1][j] != '\0') {
            final_ans |= exploreAllPaths(i+1,j, board, word.substr(1));
        }
        // right
        if(j+1 < n && board[i][j+1] != '\0') {
            final_ans |= exploreAllPaths(i,j+1, board, word.substr(1));
        } 
        // left
        if(j-1 >= 0 && board[i][j-1] != '\0') {
            final_ans |= exploreAllPaths(i,j-1, board, word.substr(1));
        }
        

        // mark cur cell as unvisited(for other recursive calls)
        board[i][j] = cell_value;

        // what is word.substr(1) is empty But from curcell -> we cannot go to any neighboring cell
            // then ans should be true 
            // but (here) final_ans = false SO check earlier only

        if(final_ans) return final_ans;
        return 0;
    }

    bool exist(vector<vector<char>>& board, string word) {
        // search all the elem of board to search for the 0th letter of word.
        int m = board.size(), n = board[0].size();

        for(int i = 0; i < m; ++i) {
            for(int j = 0; j < n; ++j) {

                // check if cur cell could be a probable start of the sequence
                if(board[i][j] == word[0]) {

                    int ans = exploreAllPaths(i,j,board,word);

                    if(ans) return true;
                }
            }
        } 

        return false;
    }
};