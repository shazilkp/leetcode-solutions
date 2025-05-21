class Solution {
public:
    int mySqrt(int x) {
        if(x == 0){
            return 0;
        }
        if(x == 1 || x == 2 || x == 3){
            return 1;
        } 
        if(x == 4){
            return 2;
        }
        int l = 0;
        int r = x/2;

        int mid;
        while(l <= r){
            mid = l + (r-l)/2;
            
            if(mid > 46340 || mid * mid > x){
                r = mid -1;
            }
            else if(mid * mid == x){
                return mid;
            }
            
            else if(mid * mid < x){
                l = mid + 1;
            }
        }
        if(mid * mid > x){
            return mid-1;
        }
        else{
            return mid;
        }
        
    }
};
