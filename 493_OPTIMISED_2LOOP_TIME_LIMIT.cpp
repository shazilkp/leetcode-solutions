class Solution {
public:
    int reversePairs(vector<int>& nums) {
        int n = nums.size();
        
        vector<pair<long int,int>> mapped;
        
        for(int i = 0 ; i < n ; i++){
            mapped.push_back({nums[i],i});
        }
        sort(mapped.begin(),mapped.end());
        int count = 0;
        for(int i = 0; i < n ; i++){
            if((long)mapped[i].first * 2 >= (long)mapped[n-1].first){
                break;
            }
            int index = mapped[i].second;
            int j = index-1;
            while(j >= 0){
                if((long)nums[j] > (long)2 * nums[index]){
                    count++;
                }
                j--;
            }
        }

        /*
        int i = n-2;
        int j = n-1;
        while(i < j && i>=0 && j >=0){
            if(mapped[j].first > 2 * mapped[i]){
                if(mapped[i].second < mapped[j].second){
                    count++;
                }
                ++j;
                --i;
            }
            else{
                --i;
            }
        }
        */
        /*
        unordered_map <long int,vector<pair<int,long int>>> mp;
        int count = 0;
        for(int i = 0; i< n-1; i++){
            if(mp.find(nums[i]) != mp.end()){
                for(auto t: mp[nums[i]]){
                    if(t.first > i){
                        count++;
                    }
                }
            }
            else{
                for(int j = i+1; j < n; j++ ){
                    if((long)nums[i] > (long)2 * nums[j]){
                        count++;
                        mp[nums[i]].push_back({j,nums[j]});
                    }
                }
            }
        }
        */
        return count;
    }
};
