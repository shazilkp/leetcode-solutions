class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        /*
        int n = arr.size();
        long long int sum = 0;
        for(int i = 0 ; i < n ; i++ ){
            int min = INT_MAX;
            for(int j = i ; j < n ; j++){
                if(arr[j] < min){
                    min = arr[j];
                }
                sum+=min;
            }
        }
        return sum % 1000000007;
        */
        int n = arr.size();
        stack<pair<int,int>> stk_n,stk_p;

        vector<int> left(n);       //dist to previous less element
        vector<int> right(n);      //dist to next less element

        for(int i = 0 ; i < n ; i++){
            left[i] = i + 1;        //previous less out of array
            right[i] = n -i;        //next less out of array
        }

        for(int i = 0 ; i < n ; i++){
            while(!stk_p.empty() && stk_p.top().first > arr[i]){
                stk_p.pop();
            }
            if(stk_p.empty()){
                left[i] = i+1;      //default value
            }
            else{
                left[i] = i - stk_p.top().second;   //dist between i and prev small of i
            }
            stk_p.push({arr[i],i});
        }

        for(int i =  n-1 ; i >= 0 ; --i){
            while(!stk_n.empty() && stk_n.top().first >= arr[i]){
                stk_n.pop();
            }
            if(stk_n.empty()){
                right[i] = n-i;
            }
            else{
                right[i] = stk_n.top().second - i;
            }
            stk_n.push({arr[i],i});
        }
        
        int ans = 0;
        for(int i = 0 ; i < n ; i++){
            ans = (ans + ((1LL * arr[i] * left[i]) % 1000000007 * right[i]) % 1000000007) % 1000000007;

        }
        return ans;

    }
};
