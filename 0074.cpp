class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
    
        //index = (i * width) + j;
        int m = matrix.size();
        int n = matrix[0].size();
        
        int l = 0;
        int r = (m-1) * n + (n-1);

        while(l <= r){
            int mid = l + (r-l)/2;
            int mid_row = mid / n;
            int mid_col = mid % n;
            if(matrix[mid_row][mid_col] == target){
                return true;
            }
            else if(matrix[mid_row][mid_col] < target){
                l = mid + 1;
            }
            else {
                r = mid-1;
            }
        }
        return false;



    }
};
