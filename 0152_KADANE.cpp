class Solution {
public:

    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        int r = 1;
        int rN =1;
        int m = nums[0];
        for(int i = 0 ; i < n ; i++){
            int r2;
            if(nums[i] < 0){    //the number is negetive
                if(rN * nums[i] > nums[i]){    //the most prev neg * this num is bigger than teh array with just this number
                    r2 = rN * nums[i];
                }
                else{
                    r2 = nums[i];
                }

                m  = max(m,r2);
                if(r * nums[i] < nums[i]){     //the largest positive possible num * this num is more negetive than the current number
                    rN = r * nums[i];
                }
                else{
                    rN = nums[i];
                }
                r = r2;
            }
            else{
                if(r * nums[i] > nums[i]){ //the most positive prev * num is bigger than current
                    r2 = r * nums[i];
                }
                else{
                    r2 = nums[i];
                }
                m  = max(m,r2);
                if(rN * nums[i] < nums[i]){        //the most negetive * this is more negetive than this
                    rN = rN * nums[i];
                }
                else{
                    rN = nums[i];
                }
                r=r2;
            }

        }
        return m;
    }
};
