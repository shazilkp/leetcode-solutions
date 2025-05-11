class Solution {
public:
    
    int mod_pow(int x, int n, int mod) {
        int result = 1;        
        x = x % mod;                   

        while (n > 0) {
            if (n % 2 == 1) {          // If the current bit is 1,then it exist in final mod, multiply result with current x
                result = (result * x) % mod;
            }
            x = (x * x) % mod;         // check if next power exist
            n = n / 2;                 // Move to the next bit (right shift)
        }

        return result;
    }
    int superPow(int a, vector<int>& b) {
        if(a % 1337 == 0){
            return 0;
        }
        int k = 1337;
        int kSize = 4;
        int bSize = b.size();
        int prev = b[0] % 1140;
        for(int i = 1 ; i < bSize ; i++){
            prev = (prev * 10 + b[i]) % 1140;
        }
        if(prev == 0){
            prev = 1140;   //case when a is not coprime with n and b is a multiple of phi(n)
        }
        //prev containns b % phi(k)
        return mod_pow(a,prev,k);
    }
};
