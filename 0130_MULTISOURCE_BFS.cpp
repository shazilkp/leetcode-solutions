class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int m = board.size();
        int n = board[0].size();

        queue<vector<int>> q;
        for(int i = 0 ; i < n ; i++){
            if(board[0][i] == 'O'){
                q.push({0,i});
                board[0][i] = 'M';
            }
        }
        for(int i = 1 ; i < m ; i++){
            if(board[i][n-1] == 'O'){
                q.push({i,n-1});
                board[i][n-1] = 'M';
            }
        }

        if(m > 1){
            for(int i = n-2 ; i >= 0 ; i--){
                if(board[m-1][i] == 'O'){
                    q.push({m-1,i});
                    board[m-1][i] = 'M';
                }
            }
        }

        if(n > 1){
            for(int i = m-2; i >= 0 ; i--){
                if(board[i][0] == 'O'){
                    q.push({i,0});
                    board[i][0] = 'M';
                }
            }
        }

        while(!q.empty()){
            vector curr = q.front(); q.pop();
            int row = curr[0];
            int col = curr[1];

            if(row+1 < m && board[row+1][col] == 'O'){
                q.push({row+1,col});
                board[row+1][col] = 'M';
            }

            if(col+1 < n && board[row][col+1] == 'O'){
                q.push({row,col+1});
                board[row][col+1] = 'M';
            }

            if(row - 1 >= 0 && board[row-1][col] == 'O'){
                q.push({row-1,col});
                board[row-1][col] = 'M';
            }

            if(col-1 >= 0 && board[row][col-1] == 'O'){
                q.push({row,col-1});
                board[row][col-1] = 'M';
            }
        }

        for(int i = 0 ; i < m ; i++){
            for(int j = 0 ; j < n ; j++){
                if(board[i][j] == 'M'){
                    board[i][j] = 'O';
                }
                else{
                    board[i][j] = 'X';
                }
            }
        }
    }
};
