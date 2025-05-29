class Solution {
public:
    int minBitFlips(int start, int goal) {
        int t = start ^ goal;
        int c = 0;
        while(t){
            if((t & 1) == 1){
                c++;
            }
            t = t >> 1;
        }
        return c;
    }
};
