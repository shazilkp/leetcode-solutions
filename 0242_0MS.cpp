class Solution {
public:
    bool isAnagram(string s, string t) {
        int a1[26];
      
        if(s.length() != t.length()){
            return false;
        }

        for(int i = 0 ; i < 26 ; i++){
            a1[i] = 0;
        }

        for(int i = 0 ; i < s.length() ; i++){
            a1[s[i] - 'a']++;
            a1[t[i] - 'a']--;
        }

        for(int i = 0 ; i < 26 ; i++){
            if(a1[i] != 0){
                return false;
            }
        }
        return true;
    }
};
