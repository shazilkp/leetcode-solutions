class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int count = 0;
        int n = nums.size();
        for(int i = 0; i < n ; i++){
            count = count ^ nums[i];
        }
        return count;
        
    }
};
