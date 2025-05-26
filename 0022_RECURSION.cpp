class Solution {
public:
    

    void helper(int n, vector <string> & res ,string s,int a,int b){
       
        if(a >= n && b >= a){
            res.push_back(s);
            return;
        }

        if(a < n){       //opening
            s = s + '(';
            helper(n,res,s,a+1,b);
            s.pop_back();
        }
        if(b < a){
            s = s + ')';
            helper(n,res,s,a,b+1);
            s.pop_back();
        }

    }
    vector<string> generateParenthesis(int n) {
        stack <int> t;
        vector<string> res;
        
        if(n == 0){
            return res;
        }

        string s = "(";
        helper(n,res,s,1,0);
        return res;
    }
};
