class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int count = 0;
        int rows = grid.size();
        int cols = grid[0].size();

        list<vector<int>> pos2;
        for(int i = 0; i< rows; i++){
            for(int j = 0; j < cols ; j++){
                if(grid[i][j] == 2){
                    pos2.push_back({i,j});
                }
            }
        }

        int lastChild = pos2.size();
        int check=0;
        while(!pos2.empty()){
            vector<int> ele = pos2.front();
            pos2.pop_front();
            lastChild--;
            
            int i = ele[0];
            int j = ele[1];
            

            if(i+1 < rows && grid[i+1][j] == 1){
                grid[i+1][j] = 2;
                pos2.push_back({i+1,j});
            
                check=1;
            }
            if(j-1>=0 && grid[i][j-1] == 1){
                grid[i][j-1] = 2;
                pos2.push_back({i,j-1});
            
                check=1;
            }
            if(i-1 >= 0 && grid[i-1][j] == 1){
                grid[i-1][j] = 2;
                pos2.push_back({i-1,j});
              
                check=1;
            }
            if(j+1 < cols && grid[i][j+1] == 1){
                grid[i][j+1] = 2;
                pos2.push_back({i,j+1});
              
                check=1;
            }

            
            if(lastChild == 0 && check == 1){
                count++;
            }
            if(lastChild == 0){
                check=0;
                lastChild = pos2.size();
            }

        }

        for(int i = 0; i< rows; i++){
            for(int j = 0; j < cols ; j++){
                if(grid[i][j] == 1){
                    return -1;
                }
            }
        }

        return count;


 
    }
};
