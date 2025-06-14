class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.length();
        int count[256];
        for(int i = 0 ; i < 256 ; i++){
            count[i] = 0;
        }
        int l = 0;
        int r = 0;
        int m = 0;
        while(r < n){
            count[s[r]]++;
            r++;
            

            while(count[s[r-1]] > 1){
                count[s[l]]--;
                l++;
            }
           // cout << l  << " " << r << "\n";
            m = max(m,r-l);
        }
        return m;
    }
};
