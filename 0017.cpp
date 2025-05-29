class Solution {
public:
    void helper(string digits,string temp,unordered_map < int, vector <char>> mp,int i,vector<string> &res){
        if(i >= digits.length()){
            //cout << "hello";
            res.push_back(temp);
            return;
        }

        char c = digits[i];
        vector <char> v = mp[c -'0'];

    
        for(int j = 0 ;  j < v.size() ; j++ ){
            temp = temp + v[j];
            helper(digits,temp,mp,i+1,res);
            temp.pop_back();
        }
    }

    vector<string> letterCombinations(string digits) {
        if(digits.length() == 0){
            return {};
        }
        unordered_map < int, vector <char>> mp;
        char c = 'a';
        for(int i = 2 ; i <= 9 ; i++){
            int count = (i == 7 || i == 9) ? 4 : 3;
            vector <char> v;
            for(int j = 0 ; j < count ; j++){
                v.push_back(c++);
            }
            mp[i] = v;
        }

        /*
        for(auto k : mp){
            cout << k.first << " : ";
            for(auto t : k.second){
                cout << t << " ";
            }
        }
        */
        vector<string> res;
        string temp = "";
        helper(digits,temp,mp,0,res);
        return res;

    }
};
