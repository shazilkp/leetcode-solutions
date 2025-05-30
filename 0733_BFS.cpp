class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        queue<vector<int>> q;
        int m = image.size();
        int n = image[0].size();
   
        vector<vector<int>> visited(m, vector<int>(n, 0));
   
        
        q.push({sr,sc});
        visited[sr][sc] = 1;
        while(!q.empty()){
            vector <int> curr = q.front();
            q.pop();
            int row = curr[0];
            int col = curr[1];
           
            if(row + 1 < m && !visited[row+1][col] && image[row+1][col] == image[row][col]){
                q.push({row+1,col});
               
            }
            if(row - 1 >= 0 && !visited[row-1][col] && image[row-1][col] == image[row][col] ){
                q.push({row-1,col});
              
            }
            if(col + 1 < n && !visited[row][col+1] && image[row][col+1] == image[row][col]){
                q.push({row,col+1});
               
            }
            if(col - 1 >= 0 && !visited[row][col-1] && image[row][col-1] == image[row][col]){
                q.push({row,col-1});
                cout << "4\n";
            }

            visited[row][col] = 1;
            image[row][col] = color;
        }
        return image;
    }
};
