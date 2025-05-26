class Solution {
public:
    bool isPowerOfTwo(int n) {
        int c = 0;
        if(n < 0){
            return false;;
        }
        while(n){
            c = c + (n & 1);
            n = n >> 1;
        }
        if(c == 1){
            return true;
        }
        else{
            return false;
        }
    }
};
