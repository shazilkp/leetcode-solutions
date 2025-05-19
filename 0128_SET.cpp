class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size() == 0){
            return 0;
        }
        set <int> mp;
        for(auto i: nums){
            mp.insert(i);
        }
        int last = INT_MIN;
        int c = 1;
        int max = 1;
        for(auto i: mp){
            //cout << i << " " << last << "\n";
            if(i == last + 1){

                c++;
                if(c > max){
                    max = c;
                }
                last = i;
            }
            else{
                last = i;
                c=1;
            }
            
            
        } 
        return max;
    }
};
