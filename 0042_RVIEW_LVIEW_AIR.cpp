class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        int rmax = height[0];
        long long int air =0;
        int sum = 0;
        for(int i = 0 ; i < n ; i ++){
            sum+=height[i];
            if(height[i] > rmax){
                air = air + ((height[i] - rmax) * i);
                rmax = height[i];
            }
        }

        //rmax  is max here too
        int lmax = height[n-1];
        for(int j = n-1 ; j >= 0 && height[j] <= rmax; --j){
            if(height[j] > lmax){
                air +=((height[j] - lmax) * (n-1 - j));
                lmax = height[j];
            }
        }
     ]


        return ((n * rmax) - air - sum);
    }

    

};
