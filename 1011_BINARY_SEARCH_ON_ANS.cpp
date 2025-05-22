class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        //we want to partition the array such that max(sum(partition_i)) is minimised
        //possible value of max(sum(partition_i)) is between when partition is smallest ie single element and partition largest
        //when partition is single element max(sum(partition_i)) = max(array)
        //when partition is whole array max(sum(partition_i)) = sum(array);


        int l = *max_element(weights.begin(),weights.end());
        int r = accumulate(weights.begin(),weights.end(),0);

        while(l < r){
            int mid = l + (r-l)/2;
            int num_part = 1;
            int sum = 0;
            int c = 0;
            for(auto &i: weights ){
                sum+=i;
                if(sum > mid){
                    num_part++;
                    sum = i;
                }
                else if(sum == mid && c < weights.size()-1){
                    num_part++;
                    sum = 0;
                }
                c++;
            }
            if(num_part <= days){
                r = mid;
            }
            else if(num_part > days){
                l = mid +1;
            }
        }
        return r;
    }
};
