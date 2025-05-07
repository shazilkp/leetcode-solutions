class Solution {
public:
    void swap(vector<int>& nums,int i,int j){
        //cout << "before swap" << nums[i] << "," << nums[j] << "\n";
        int t = nums[i];
        nums[i] = nums[j];
        nums[j] = t;
       // cout << "after swap" << nums[i] << "," << nums[j] << "\n";
    }
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        int i = n-1;
        int l = nums[n-1];
        for(i = n -1; i >= 0; i--){
            if(nums[i] < l){
                int j = i+1;
                for(j = i+1; j < n ; j++){
                    if(nums[j] <= nums[i]){

                        break;
                    }
                }
                swap(nums,j-1,i);
                break;
            }
            else{
                l = nums[i];
            }
        }
        i++;
        sort(nums.begin() + i,nums.end());
        //cout <<"final i" << i;
        /*
        while(i<n){
            smallest[n-1] = nums[n-1];
            
            smallIndex[n-1] = n-1;
            for(int k = n-2 ; k >= 0 && k>=i ; --k){
                if(nums[k] < smallest[k+1]){
                    smallest[k] = nums[k];
                    smallIndex[k] = k;

                }
                else{
                    smallest[k] = smallest[k+1];
                    smallIndex[k] = smallIndex[k+1];
                }
            }

            for(int t = i ; t < n ; t++){
                
            }
            if(nums[i] > smallest[i]){
                
                swap(nums,i,smallIndex[i]);
            }
            i++;
        }
        */

    }
};
