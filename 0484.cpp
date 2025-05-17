class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int f= 0;
        int n = nums.size();
        int count = 0;
        int max = 0;
        for(int i = 0 ; i < n; i++){
            if(f== 0 && nums[i] == 1){
                f = 1;
                count++;
            }
            else if(f == 1 && nums[i] == 1){
                count++;
            }
            else if(f== 1 && nums[i] != 1){
                if(count > max){
                    max = count;
                }
                count = 0;
                f = 0;
            }
        }
        if(count > max){
            max = count;
        }
        return max;
        
    }
};
