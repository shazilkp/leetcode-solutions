class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();            //contains n of n+1
        int sum = 0;
        for(auto i : nums){
            sum+=i;
        }

        int t = n*(n + 1)*0.5;
        return t - sum;

    }
};
