class KthLargest {
public:
    vector<int>big;
    int k_;
    KthLargest(int k, vector<int>& nums) {
        big = nums;
        sort(big.begin(),big.end(),greater<int>());
        k_ = k -1;
    }
    
    int add(int val) {
        int i = 0;
        int limit = k_ < big.size() ? k_ : big.size();

        for( i = 0 ; i < big.size() ; i++){
            if(val < big[i]){
                continue;
            }
            else{
                
                break;
            }
        }
        big.insert(big.begin() + i, val);
        if(big.size() > k_){
            big.erase(big.begin() + k_ + 1,big.end());
        }
        // for(auto t : big){
        //     cout << t <<" ";
        // }
        // cout << "\n";
        if(big.size() >0 && big.size() >= k_){
            return big[k_];
        }
        else if(big.size() > 0){
            return big[big.size()-1];
        }
        return -1;
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */
