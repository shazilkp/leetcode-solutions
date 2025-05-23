class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        //search from diagonal corners
        int m = matrix.size(); //rows
        int n = matrix[0].size(); //cols

        int top_col = n -1;
        int top_row = 0;

        int side_col= 0;
        int side_row = m -1;

     
        while(top_col >= 0 && top_row <= m-1 && side_col <= n-1 && side_row >=0 ){
            if(target == matrix[top_row][top_col]){
                return true;
            }
            if(target == matrix[side_row][side_col]){
                return true;
            }

            if(target > matrix[top_row][top_col]){
                top_row++;
            }
            else{
                top_col--;
            }

            if(target > matrix[side_row][side_col]){
                side_col++;
            }
            else{
                side_row--;
            }
        }
        

        return false;
    }
};
