class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();       //no of nodes
        vector<int>visited(n,0);

        queue<int> q;

        for(int i = 0 ; i < n ; i++){
            if(visited[i] == 0){//unprocessed
                //bfs
                q.push(i);
                visited[i] = 1;

                while(!q.empty()){
                    int curr = q.front(); q.pop();
                    //cout << "curr = " << curr;
                    for(int j = 0 ; j < graph[curr].size() ; j++){
                        if(visited[graph[curr][j]] == 0){
                            q.push(graph[curr][j]);
                            visited[graph[curr][j]] = -visited[curr];
                        }
                        else if(visited[graph[curr][j]] != -visited[curr]){
                            //cout << graph[curr][j] << " " << curr; 
                            return false;
                        }
                    }
                }
            }
        }
        return true;
    }
};
