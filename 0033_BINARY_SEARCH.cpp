class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int l = 0;
        int r = n-1;
 
        while(l <= r){
            int mid = l + (r-l)/2;
            if(nums[mid] == target){
                return mid;
            }

            if(nums[l] <= nums[mid]){        //left proper
                if(nums[l] <= target && target < nums[mid]){        //target lies in left proper
                    r = mid-1;
                }
                else{       //target in lies in the improper right
                    l = mid + 1;
                }
            }

            else{        //right proper
                if(nums[r] >= target && target > nums[mid]){        //target lies in right proper
                    l = mid + 1;
                }
                else {       //target in lies in the improper left
                    r = mid - 1;
                }
            }
            
        }

        return -1;
    }
};
