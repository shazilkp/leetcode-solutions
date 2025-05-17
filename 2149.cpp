class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        vector<int>pos;
        vector<int>neg;
        int n = nums.size();
        for(auto i: nums){
            if(i > 0){
                pos.push_back(i);
            }
            else if(i < 0){
                neg.push_back(i);
            }
        }


        for(int i = 0 ; i < n ;i ++){
            nums[i] = (i%2 == 0 ? pos[i/2] : neg[i/2]);
        }
        return nums;

    }
};
