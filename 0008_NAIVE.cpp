class Solution {
public:
    int myAtoi(string s) {
        int i = -1;
        int firstCharRead = 0,pos = 1,signRead=0;
        int overflow = 0;
        long int val = 0;
        int returnVal;
        while(s[++i]){
            if(s[i] == ' ' && firstCharRead == 0){
                continue;
            }
            if(signRead == 1 && (s[i] == '-' || s[i] == '+')){
                break;
            }
            if(firstCharRead == 0 && s[i] == '-'){
                pos = -1;
                signRead = 1;
                continue;
            }

            if(firstCharRead == 0 && s[i] == '+'){
                pos = 1;
                firstCharRead = 1;
                signRead = 1;
                continue;
            }
          
            if(firstCharRead == 0 && s[i] >= '0' && s[i] <= '9'){
                firstCharRead = 1;
                val = val *10 + (s[i] - '0');
                continue;
            }

            if(firstCharRead == 1 && s[i] >= '0' && s[i] <= '9'){
                if((val *10 + (s[i] - '0')) >= 2147483647 && pos == 1){
            
                    overflow = 1;
                    break;
                }
                else if((val *10 + (s[i] - '0')) >= 2147483648 && pos == -1){
                    overflow = 1;
                }
                else{
                    val = val *10 + (s[i] - '0');
                }
            }
            else{
                break;
            }
        }
        if(overflow == 1){
            if(pos == 1){
                returnVal = 2147483647;
            }
            else if(pos == -1){
                returnVal = -2147483648;
            }
        }
        else{
            returnVal = val * pos;
        }
        return returnVal;
    }
};
