class Solution {
public:
    int findDuplicate(vector<int>& nums) {

        int n = nums.size();
        for(int i = 0 ; i < n ; i++){
            int t = abs(nums[i]);
            if(nums[t] < 0){
                return t;
            }
            else{
                nums[t] = -nums[t];
            }
        }
        return 0;
    }
};
