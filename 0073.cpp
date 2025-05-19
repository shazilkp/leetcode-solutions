class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        vector <vector<int>> v;
        int  m = matrix.size(); //rows
        int n = matrix[0].size(); //cols

        for(int i = 0 ; i < m ; i++ ){
            for(int j = 0 ; j < n ; j++){
                if(matrix[i][j] == 0){
                    v.push_back({i,j});
                }
            }
        }

        for(auto index : v){
            for(int i = 0 ; i < m ; i++ ){
                matrix[i][index[1]] = 0;
            }
            for(int j = 0 ; j < n ; j++){
                matrix[index[0]][j] = 0; 
            }
        }
    }
};
