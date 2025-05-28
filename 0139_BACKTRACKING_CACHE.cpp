class Solution {
public:
    unordered_map <int,bool> mp;
    int helper(vector<string>& wordDict, string s,int start){
        if(start >= s.length()){
            return 1;
        }
        if(mp.find(start) == mp.end()){
            mp[start] = true;
        }

        for(int len = 1; len <= s.length() - start  ; len++){
            string t = s.substr(start,len);
            if(find(wordDict.begin(), wordDict.end(),t) != wordDict.end()){
                if(mp.find(start + len) == mp.end()){   //not explored
                    if(helper(wordDict,s,start + len) == 1){
                        return 1;
                    }
                    else{
                        mp[start + len] = false;
                    }
                }
                //if already found
                if(mp[start + len] == true){
                    return 1;
                }
            }
        }
        return 0;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        return helper(wordDict,s,0);
    }
};
