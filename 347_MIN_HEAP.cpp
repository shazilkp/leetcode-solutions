class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        
        map<int, int> myMap; 
        int n = nums.size();
    

        for (auto i : nums){
            myMap[i]++;
        }

      
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> minHeap;
        for (const auto& [key, val] : myMap) {
            minHeap.emplace(val, key);  // val first, to compare values

            if (minHeap.size() > k)
                minHeap.pop();  // remove smallest
        }

        vector<int> topk;
        while (!minHeap.empty()) {
            topk.push_back(minHeap.top().second);
            minHeap.pop();
        }

        return topk;



    }
};
