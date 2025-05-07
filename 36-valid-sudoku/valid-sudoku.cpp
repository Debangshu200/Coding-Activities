
class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        // Didn't not understand this at all, how are the vectirs are being generated.
        vector<vector<bool>> rows(9, vector<bool>(9, false));
        vector<vector<bool>> columns(9, vector<bool>(9, false));
        // I did not undertsand the third part entirely, it should be 3*3 sub-matrix
        vector<vector<bool>> subBox(9, vector<bool>(9, false));

        for(int r = 0; r < 9; r++) {
            for(int c = 0; c < 9; c++) {
                // the current character
                char currentChar = board[r][c];
                // Skip if the cell is empty (denoted by '.').
                if(currentChar == '.')
                    continue;
        //This is not clear--        // Convert char digit to integer index (0 to 8).
                int num = currentChar - '0' - 1;
        //this part is not clear--        // calculating the sub-box index using the formula for rows and columns
                int subBoxIndex = (r/3)* 3 + (c/3);
                // we are checking row, column and subBox for duplicate
                if(rows[r][num] || columns[c][num] || subBox[subBoxIndex][num]){
                    return false;
                }
                //we are making the index as true for all three 2D vector, as it is has been seen
                rows[r][num] = true;
                columns[c][num] = true;
                subBox[subBoxIndex][num] = true;
            }
        }
        // If all checks pass, then the board is valid.
        return true;
    }
};