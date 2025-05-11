class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        int totWat = 0;
        int start = 0;
        int end = n;
        while(1){       //layer loop
            int sum = 0;
            int f=0;
            int oldEnd = end;
            int oldStart = start;
            for(int i = oldStart ; i <= oldEnd ; i ++){
                if(height[i] > 0){
                    if(f == 0){
                        f=1;
                        start = i;
                    }
                    end = i;
                }
                sum+=height[i];
            }
            //cout << start << " " << end << "\n";

            if(sum == 0 || sum == 1){
                break;
            }
            int i=start;
            int water = 0;
            while(i < end){
                
                if(height[i] == 0){
                  water++;

                }


                i++;
            }
            //cout <<"layer contains" << water<< "\n";
            totWat += water;
            for(int i = 0 ; i < n ; i ++){
                if(height[i] > 0){
                    height[i]--;                        
                }
            }

        }
        //cout <<"total water" << totWat<< "\n";
        return totWat;
    }
};
