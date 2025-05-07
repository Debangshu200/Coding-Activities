#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<vector<bool>> rows(9, vector<bool>(9, false));
        vector<vector<bool>> columns(9, vector<bool>(9, false));
        vector<vector<bool>> subBox(9, vector<bool>(9, false));

        for(int r = 0; r < 9; r++) {
            for(int c = 0; c < 9; c++) {
                char currentChar = board[r][c];

                if(currentChar == '.')
                    continue;
                int num = currentChar - '0' - 1;

                int subBoxIndex = (r/3)* 3 + (c/3);

                if(rows[r][num] || columns[c][num] || subBox[subBoxIndex][num]){
                    return false;
                }

                rows[r][num] = true;
                columns[c][num] = true;
                subBox[subBoxIndex][num] = true;
            }
        }
        return true;
    }
};