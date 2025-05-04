using namespace std;

class Solution {

public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> res;

        map<int, vector<vector<int>>> sum2nums;
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


        auto left = sum2nums.begin();
        auto right = std::prev(sum2nums.end()); 

        while(left != right && std::distance(left,right) > 0){
            int s = left->first + right->first;
            if(s == target){
                for(const auto &p1: left->second){
                    for(const auto &p2: right->second){
                        if (p1[0] != p2[0] && p1[0] != p2[1] && p1[1] != p2[0] && p1[1] != p2[1]) {
                            // Found a valid quadruple
                            res.push_back({nums[p1[0]],nums[p1[1]],nums[p2[0]],nums[p2[1]]});
                        }
                    }
                }
                ++left;
                --right;
            }
            else if(s < target){
                ++left;
            }
            else{
                --right;
            }
        }
        if (left == right) {
        int sum = left->first + left->first; // sum + sum
        if (sum == target) {
            const auto& pairs = left->second;
            for (int i = 0; i < pairs.size(); ++i) {
                for (int j = i + 1; j < pairs.size(); ++j) {
                    if (pairs[i][0] != pairs[j][0] && pairs[i][0] != pairs[j][1] && pairs[i][1] != pairs[j][0] && pairs[i][1] != pairs[j][1]) {
                        // Valid combination of distinct pairs
                        res.push_back({nums[pairs[i][0]],nums[pairs[i][1]],nums[pairs[j][0]],nums[pairs[j][1]]});
                    }
                }
            }
        }
    }
    std::set<std::vector<int>> unique_sorted;

    for (auto& vec : res) {
        std::sort(vec.begin(), vec.end());       // Sort the inner vector
        unique_sorted.insert(vec);               // Set ensures uniqueness
    }

    // Convert set back to vector if needed
    std::vector<std::vector<int>> result(unique_sorted.begin(), unique_sorted.end());
        
        return result;
    }

    


};
