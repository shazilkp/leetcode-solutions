class Solution {
public:
    void swap(vector<int>&nums,int i,int j){
        int t = nums[i];
        nums[i] = nums[j];
        nums[j] = t;
    }

    void moveZeroes(vector<int>& nums) {
        int n = nums.size();
        for(int i = 0 ; i < n ; i++){
            if(nums[i] != 0){
                int j = i-1;
                while(j >= 0 && nums[j] == 0){
                    j--;
                }
                swap(nums,j+1,i);
            }
        }
    }
};
