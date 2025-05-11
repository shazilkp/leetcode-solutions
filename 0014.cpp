class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {


        int sm = strs[0].length();
        for(int i = 1 ; i < strs.size() ; i++){
            if(strs[i].length() < sm){
                sm = strs[i].length();
            }
        }
        
        string pre = "";
        

        int j = 0;
        while(j < sm){
            char a = strs[0][j];
            for(int i = 1 ; i < strs.size() ; i++){
                if(strs[i][j] == a){
                    continue;
                }
                else{
                    return pre;
                }
            }
            pre = pre + a;
            j++;
        }
        

        return pre;
        
    }
};
