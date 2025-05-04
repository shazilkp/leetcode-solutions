using namespace std;

class Solution {

public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        set<vector<int>> res;

        unordered_map<int, vector<vector<int>>> sum2nums;
        int length = nums.size();
        if(length < 4){
            return {};
        }
        for(int i =0 ; i < length-1; i++){
            for(int j = i + 1; j < length ; j++){
                int sum = nums[i] + nums[j];
                sum2nums[sum].push_back({i,j}); 
            }
        }
        /*
        for (const auto& [sum, pairs] : sum2nums) {
            std::cout << "Sum: " << sum << " -> Pairs: ";
            for (const auto& pair : pairs) {
                std::cout << "[" << pair[0] << "," << pair[1] << "] ";
            }
            std::cout << "\n";
        }
        */


        for (int i = 0; i < length - 1; i++) {
            for (int j = i + 1; j < length; j++) {
                int s = target - (nums[i] + nums[j]);
                if (sum2nums.find(s) != sum2nums.end()) {
                    for (const auto &kl : sum2nums[s]) {
                        if (kl[0] > j && kl[1] > j) {
                            vector<int> quard = {nums[i], nums[j], nums[kl[0]], nums[kl[1]]};
                            std::sort(quard.begin(), quard.end());   
                            res.insert(quard);
                            
                        }
                    }
                }
            }
        }
    

    // Convert set back to vector if needed
    std::vector<std::vector<int>> result(res.begin(), res.end());
        
    return result;
    }

    


};
