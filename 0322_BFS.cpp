class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        if(amount == 0){
            return 0;
        }

        queue<int>q;
        unordered_set <int> visited;

        q.push(0); visited.insert(0);
        int step = 0;

        while(!q.empty()){
            int n = q.size();
            step++;
            for(int i = 0; i < n ; i++){
                int val = q.front();
                q.pop();

                for(auto j : coins){
                    int running = val + j;
                    if(running == amount){
                       
                        return step;
                    }
                    if(running < amount && (visited.find(running) == visited.end())){
                        visited.insert(running);
                        q.push(running);
                    }
                }
            }
        }
        return -1;
    }
};
