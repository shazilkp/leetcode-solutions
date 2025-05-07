class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> res;
        int n = nums.size();
        if (n < 4) return res;
        
        sort(nums.begin(), nums.end());
        if((long long)nums[n-4]+nums[n-3]+nums[n-2]+nums[n-1]<target) return res;
        for (int i = 0; i < n - 3; ++i) {
            if (i > 0 && nums[i] == nums[i - 1]) continue; // skip duplicates
            for (int j = i + 1; j < n - 2; ++j) {
                if (j > i + 1 && nums[j] == nums[j - 1]) continue; // skip duplicates

                int left = j + 1;
                int right = n - 1;

                while (left < right) {
                    long long sum = (long long)nums[i] + nums[j] + nums[left] + nums[right];
                    if (sum == target) {
                        res.push_back({nums[i], nums[j], nums[left], nums[right]});
                        ++left;
                        --right;

                        while (left < right && nums[left] == nums[left - 1]) ++left; // skip duplicates
                        while (left < right && nums[right] == nums[right + 1]) --right; // skip duplicates
                    } else if (sum < target) {
                        ++left;
                    } else {
                        --right;
                    }
                }
            }
        }

        return res;
    }
};
