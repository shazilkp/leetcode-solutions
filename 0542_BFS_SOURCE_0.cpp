class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        queue<vector<int>> q;
        //vector<vector<int>> res(m,vector <int>(n,INT_MAX));
        
        for(int i = 0 ; i < m ; i++){
            for(int j = 0 ; j < n ; j++){
                if(mat[i][j] == 0){
                    q.push({i,j});
                }
                else{
                    mat[i][j] = -1;
                }
            }
        }

        while(!q.empty()){
            auto curr = q.front();
            int row = curr[0];
            int col = curr[1];
            q.pop();
            if(row + 1 < m && mat[row+1][col] == -1){
                mat[row+1][col] = mat[row][col] + 1;
                q.push({row+1,col});
            }
            if(row - 1 >= 0 && mat[row-1][col] == -1){
                mat[row-1][col] = mat[row][col] + 1; 
                q.push({row-1,col});
            }
            if(col + 1 < n && mat[row][col+1] == -1){
                mat[row][col+1] = mat[row][col] + 1; 
                q.push({row,col+1});
            }
            if(col - 1 >= 0 && mat[row][col-1] == -1){
                mat[row][col-1] = mat[row][col] + 1; 
                q.push({row,col-1});
            }
        }
        
        return mat;
    }
};
