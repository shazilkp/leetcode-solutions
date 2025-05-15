class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        int n = nums.size();
        queue<vector <int>> q;
        vector<vector<int>> result;

        q.push({});

        while(!q.empty()){
            vector <int> curr = q.front();
            q.pop();

            int f = 0;
            for(int i = 0 ; i < n ; i++){
                if(find(curr.begin(),curr.end(),nums[i]) == curr.end()){
                    f =1;
                    vector <int> r = curr;
                    r.push_back(nums[i]);
                    q.push(r);
                }
            }
            if(f == 0){
                result.push_back(curr);
            }
        }
        return result;
    }
};
