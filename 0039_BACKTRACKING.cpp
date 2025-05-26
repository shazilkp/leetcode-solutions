class Solution {
public:
    void helper(vector<int> nums ,vector<vector<int>> &res, int target,int start, vector <int> temp){
        
        int sum = 0;
        for(auto j : temp){
            sum+=j;
        }
        if(sum == target){
            res.push_back(temp);
            return;
        }
        

        for(int i = start ; i < nums.size() ; i++ ){
            if(nums[i] <= target - sum){
                temp.push_back(nums[i]);
                helper(nums, res, target, i,temp);
                temp.pop_back();
            }
            else{
                break;
            }
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        vector<int> t;
        sort(candidates.begin(),candidates.end());
        helper(candidates,res,target,0,t);
        return res;
    }
};
