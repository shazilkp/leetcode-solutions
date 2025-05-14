class Solution {
public:
    int compareVersion(string version1, string version2) {
        int l1 = version1.length();
        int l2 = version2.length();
        int c1 = count(version1.begin(),version1.end(),'.');
        int c2 = count(version2.begin(),version2.end(),'.');
        int k = -1;
        int j;
       
        for(int i = 0 ; i < l1; i++){
            int num1 = 0;
            j = i;
            while(j < l1 && version1[j]!='.'){
                num1 = num1 * 10 + (version1[j] - '0');
                j++;
            }

            k++;
            int num2 = 0;
            while(k < l2 && version2[k] != '.'){
                num2 = num2 * 10 + (version2[k] - '0');
                k++;
            }
            if(num1 > num2){
                return 1;
            }
            if(num1 < num2){
                return -1;
            }
            i = j;
        }

        int flag = 0;
        if(j < l1 - 1){ //version1 larger
            while(j < l1){
                if(version1[j] != '0' && version1[j] != '.'){
                    flag = 1;
                }
                j++;
                
            }
            if(flag){
                return 1;
            }

        }

        flag = 0;
        if(k < l2 - 1){ //version2 larger
            while(k < l2){
                if(version2[k] != '0' && version2[k] != '.'){
                    flag = 1;
                }
                k++;
                
            }
            if(flag){
                return -1;
            }

        }

        return 0;
    }
};
