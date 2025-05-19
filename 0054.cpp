class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int m = matrix.size(); //rows
        int n = matrix[0].size(); // cols
        vector <int> result;

        if(n == 1){
            for(auto i: matrix){
                result.push_back(i[0]);
            }
            return result;
        }

        int i = 0, j = 0;
        int dir = 0;

        int count  = 0;

        while(i < m && j < n && count < m * n){
            //cout << matrix[i][j] << " \n";
            result.push_back(matrix[i][j]);
            matrix[i][j] = 102;
            count++;

            if(dir == 1){
                i++;
                if(i == m-1 || (i + 1 < m && matrix[i+1][j] == 102)){
                    //cout << "dir changed " << dir <<" - ";
                    dir = (dir + 1) %4;
                    //cout << dir << "\n";
                }
            }
            else if(dir == 0){
                j++;
                if(j == n-1 ||( j+1 < n && matrix[i][j+1] == 102)){
                    //cout << "dir changed " << dir <<" - ";
                    dir = (dir + 1) %4;
                    //cout << dir << "\n";
                }
            }
            else if(dir == 3){
                --i;
                if(i == 0 ||(i >= 0 && matrix[i-1][j] == 102)){
                    //cout << "dir changed " << dir <<" - ";
                    dir = (dir + 1) %4;
                    //cout << dir << "\n";
                }

            }
            else if(dir == 2){
                --j;
                if(j == 0 || (j >= 0 && matrix[i][j - 1] == 102)){
                    //cout << "dir changed " << dir <<" - ";
                    dir = (dir + 1) %4;
                    //cout << dir << "\n";
                }

            }


        }
        return result;

    }
};
