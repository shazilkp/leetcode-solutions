class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size();
        int t = n/3;
        unordered_map <int,int> mp;
        vector <int> result;
        for(int i = 0 ; i < n ; i++){
            mp[nums[i]]++;
            if(mp[nums[i]] > n/3){
                if(find(result.begin(),result.end(),nums[i]) == result.end()){
                    result.push_back(nums[i]);
                }
                
            }
        } 
        return result;
    }
};
