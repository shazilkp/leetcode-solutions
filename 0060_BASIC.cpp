class Solution {
public:
    void removeValue(vector<int>& vec, int value) {
        auto it = lower_bound(vec.begin(), vec.end(), value);
        if (it != vec.end() && *it == value) {
            vec.erase(it);
        }
    }

    vector<long long> computeFactorials(int n) {
        vector<long long> factorials(n + 1, 1);  // factorial[0] = 1
        for (int i = 1; i <= n; i++) {
            factorials[i] = factorials[i - 1] * i;
        }
        return factorials;
    }

    string getPermutation(int n, int k) {
        vector<long long> factorials = computeFactorials(n);
        
        vector<int> nums;
        for(int i = 1 ; i <= n ; i++){
            nums.push_back(i);
        }

        int t = k-1;
        string s;
        for(int i = 0 ; i < n ; i++){
            //index = ethramathe n-1-1! multiple aaan t
            int index = t / factorials[n-i-1];
            s+= to_string(nums[index]);
            nums.erase(nums.begin() + index);
          
            t = t % factorials[n-i-1];

        }

        cout << s;
        return s;

  

    }
};
