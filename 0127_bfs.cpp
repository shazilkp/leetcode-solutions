class Solution {
public:
    bool letterDiffIsOne(string w1,string w2){
        int n = w1.length();
        int t = 0;
        for(int i = 0 ; i < n ; i++){
            if(w1[i] != w2[i]){
                t++;
                if(t > 1){
                    return false;
                }
            }
        }
        if(t == 1){
            return true;
        }
        else{
            return false;
        }
    }

    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        queue <string> q;
        q.push(beginWord);
        int size = q.size();
        int c = 1;
        while(!q.empty()){
            if(size == 0){
                size = q.size();
                c++;
            }
            string curr = q.front(); q.pop();
            //mark as visited
            for(int  i = 0 ; i < wordList.size() ; i++){
                if(wordList[i] == curr){;
                    wordList[i] = "";
                    break;
                }
            }

            if(curr == endWord){
                return c;
            }

            for(int i = 0 ; i < wordList.size() ; i++){
                if(wordList[i] != "" && letterDiffIsOne(curr,wordList[i])){
                    string word = wordList[i];
                    q.push(word);
                    wordList[i] = "";
                }
            }
            size--;
        }

        return 0;

    }
};
