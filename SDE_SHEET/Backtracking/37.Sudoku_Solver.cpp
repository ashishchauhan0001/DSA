class Solution {
public:

    bool isValid(char row,char col,char c,vector<vector<char>> &board){
            for(int i=0;i<9;i++){
                if(board[i][col]==c) return false;
                if(board[row][i]==c) return false;
                if(board[3*(row/3)+i/3][3*(col/3)+i%3]==c) return false;
            }

            return true;
    }

    bool solve(vector<vector<char>> & board){
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board.size();j++){
                if(board[i][j]=='.'){

                    for(char c='1';c<='9';c++){
                        if(isValid(i,j,c,board)){
                            board[i][j]=c;
                        if(solve(board)) return true;
                        else board[i][j]='.';
                        }
                    }
                return false; // if we are unable to place a value 
                }
            }
        }

        return true;
    }

    void solveSudoku(vector<vector<char>>& board) {
        solve(board);
    }
};