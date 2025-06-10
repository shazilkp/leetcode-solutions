class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int, int>>> adj(n);
        for (auto& t : flights) {
            adj[t[0]].push_back({t[1], t[2]});
        }


        vector<int> visited(n,0);
        vector<int> dist(n,INT_MAX);

        queue<pair<int, int>> q;
        q.push({src,0});
        dist[src] = 0;


        int step = 0;
        int t = q.size();
        while(step < k+1 && !q.empty()){
            int sz = q.size();
            for (int i = 0; i < sz; ++i) {
                auto [u,cost] = q.front(); q.pop();
                for(auto ele : adj[u]){
                    auto [v,price] = ele;
                    if(dist[v] > cost + price){
                        dist[v] = cost + price;
                        q.push({v,dist[v]});
                    }  
                }
            }
            step++;
        }


        return dist[dst] == INT_MAX ? -1 : dist[dst];
    }
};
