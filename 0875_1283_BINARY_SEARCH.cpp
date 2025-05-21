class Solution {
public:
    int helper(vector<int>& piles,int k,int h){
        int sum = 0;
        for(auto &i : piles){
            sum  = sum + ((i+k-1)/k);
            if(sum > h){
                return 1;
            }
        }
        return 0;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        long long int sum = 0;
        int max = INT_MIN;
        int n = piles.size();

        for(auto &i : piles){
            if(i > max){
                max = i;
            }
            sum+=i;
        }

        if(h == n){
            return max;
        }

        int l = (sum + h - 1)/h;        //ciel
        int r = max;

        int mid;
        while(l < r){
            mid = l + (r-l)/2;
            if(helper(piles,mid,h)){
                l = mid + 1;
            }
            else{
                r = mid;
            }
        }
        return l;
        
    }
};
