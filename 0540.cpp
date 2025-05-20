class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n = nums.size();
        int l = 0;
        int r = n -1;

        if(n == 1){
            return nums[0];
        }

        while(l <= r){
            if(r - l + 1 == 3){
                if(nums[l] == nums[l+1]){
                    return nums[r];
                }
                else if(nums[r-1] == nums[r]){
                    return nums[l];
                }
            }

            int mid = l + (r-l)/2;
            if(nums[mid+1] == nums[mid]){
                if((mid+1 - l + 1) % 2 == 1){
                    r = mid + 1;
                }
                else{
                    l = mid;
                }
            }
            else if(nums[mid - 1] == nums[mid]){
                if((r - (mid-1) +1 )% 2 == 1){
                    l = mid - 1;
                }
                else{
                    r = mid;
                }
           
            }
            else{
                return nums[mid];
            }

        }
        return -1;
    }
};
