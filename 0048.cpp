class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        for(int i = 0; i < n/2 ; i++){
            for(int j = i ; j < n-1-i ; j ++){
                int a,b,c,d;
                a = matrix[i][j];
                b = matrix[j][n-1-i];//were it is so to be gone3
                c = matrix[n-1-i][n-1-j];//where b has to be put 9
                d = matrix[n-1-j][i];

                matrix[i][j] = d;
                matrix[j][n-1-i] = a;
                matrix[n-1-i][n-1-j] = b;
                matrix[n-1-j][i] = c;
            }
        }
    }
};
