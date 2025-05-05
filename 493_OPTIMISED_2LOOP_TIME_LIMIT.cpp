class Solution {
public:
    int getMax(vector<pair<long int,int>> mapped,int n){
        int max = mapped[0].first;
        for(auto & i: mapped){
            if(max < i.first){
                max = i.first;
            }
        }
        return max;
    }
    
    int reversePairs(vector<int>& nums) {
        int n = nums.size();
        
        vector<pair<long int,int>> mapped;
        
        for(int i = 0 ; i < n ; i++){
            mapped.push_back({nums[i],i});
        }

        long int largest = getMax(mapped,n);
        //cout << largest;

        vector<pair<long int, int>> result;

        vector<long int>runningLargest;
        int l = mapped[0].first;
        for (const auto& p : mapped) {
            if (p.first * 2 <= largest) {
                result.push_back(p);
            }
            if(p.first > l){
                l = p.first;
            }
            runningLargest.push_back(l);
            cout << l << " ";
        }
        //std::sort(result.begin(), result.end()); // Optional
       
        int count = 0;
        for(int i = 0; i < result.size() ; i++){
            int index = result[i].second;
            int j = index-1;
            while(j >= 0 && runningLargest[j] > (long)2 * nums[index]){
                if((long)nums[j] > (long)2 * nums[index]){
                    count++;
                }
                j--;
            }
        }
        /*
        sort(mapped.begin(),mapped.end());
        int count = 0;
        for(int i = 0; i < n ; i++){
            if((long)mapped[i].first * 2 > (long)mapped[n-1].first){
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
        */

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
