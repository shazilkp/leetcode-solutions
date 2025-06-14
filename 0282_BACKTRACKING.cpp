class Solution {
public:
    vector<string> ans;
    void helper(string &num, int i , int target, long val, string curr,long prev){
        int n = num.size();
        if(i == n){
           // cout << curr <<"\n";
            if(val == target){
                ans.push_back(curr);
            }
            return;
        }
        string nextNum = "";
        long number =0;
        for(int j = i ; j < n ; j++){
            if(j > i && num[i] == '0'){
                break;
            }
            nextNum += num[j];
            number = number * 10 +(num[j] - '0');
            if(i == 0){
                helper(num,j+1,target,number,curr + nextNum,number);
            }
            else{
                helper(num,j+1,target,val + number,curr + "+" + nextNum, number);
                helper(num,j+1,target,val - number,curr + "-" + nextNum, -number);
                helper(num,j+1,target,val - prev + (prev * number),curr + "*" + nextNum, prev * number);
            }
        }
    }
    vector<string> addOperators(string num, int target) {
        helper(num,0,target,0,"",0);
        return ans;
    }
};
