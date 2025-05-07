class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n = nums.size();
        int ele = -1;
        for(int i = 0; i < n-1 ; i++){
            if(nums[i+1] == nums[i]){
                ele = nums[i+1];
                break;
            }
        }
        return ele;
    }
};
