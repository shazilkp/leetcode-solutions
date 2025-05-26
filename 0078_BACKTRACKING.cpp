class Solution {
public:
    void helper(vector<int> nums ,vector<vector<int>> &res, int start, vector <int> temp){
        res.push_back(temp);

        for(int i = start ; i < nums.size() ; i++ ){
            temp.push_back(nums[i]);
            helper(nums, res, i + 1, temp);
            temp.pop_back();
        }
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> t;
        helper(nums,res,0,t);

        return res;
    }
};
