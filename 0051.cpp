class Solution {
public:
    void markBoard(vector<string> &board,int i,int j){
        int n = board.size();
        for(int y = 0 ; y < n ; y++){
            for(int x = 0 ; x < n ; x++){
                if(board[y][x] == '.'){
                    if(x == j || y == i){
                        board[y][x] = 'X';
                    }
                    if(abs(x-j) == abs(y-i)){    
                        board[y][x] = 'X';
                    }                
                }
            }
        }
    }

    void helper(vector<string> board,vector<vector<string>>& sol,int count,int n,int starti,int startj){
        if(count >= n){
            sol.push_back(board);
            return;
        }

        for(int i = starti ; i < n ; i++){
            for(int j = 0 ; j < n ; j++){
                if(board[i][j] == '.'){
                    board[i][j] = 'Q';
                    vector<string> boardCopy = board;
                    markBoard(board,i,j);
                    helper(board,sol,count+1,n,i,j+1);
                    board = boardCopy;
                    board[i][j] = '.';
                }
            }
        }
    }


    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> res;
        vector<string> board;
        for(int i = 0 ; i < n ; i++){
            string t = ""; 
            for(int j = 0 ; j < n ; j ++){
                t.push_back('.');
            }
            board.push_back(t);
        }

        helper(board,res,0,n,0,0);
        for(auto &b : res){
            for(int i = 0 ; i < n ; i++){
                for(int j = 0 ; j < n ; j++){
                    if(b[i][j] == 'X'){
                        b[i][j] = '.';
                    }
                }
            }
        }
        return res;
    }
};
