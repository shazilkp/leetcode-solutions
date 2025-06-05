class Solution {
public:
    int countPrimes(int n) {
        if(n == 0 || n==1){
            return 0;
        }
        bool marked[n];
        memset(marked, false, sizeof(marked));
        n=n-1;
        int c= n-1;     //1  and n excluded
        for(int i = 2 ; i*i <= n ; i++){
            if(!marked[i]){
                for(int j = i ; j <=(n/i); j++){
                    if(!marked[i*j]){
                        marked[i*j] = true;
                        c--;
                    }
                }

            }
        }
        return c;
    }
};
