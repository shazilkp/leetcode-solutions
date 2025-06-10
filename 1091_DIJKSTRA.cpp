class Solution {
public:
    int dx[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
    int dy[8] = {-1, 0, 1, -1, 1, -1, 0, 1};

    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> visited(n, vector<int>(m , 0));
        vector<vector<int>> dist(n, vector<int>(m , INT_MAX));
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
 
        if(grid[0][0] != 0 || grid[n-1][m-1] != 0){
            return -1;
        }

        int count = n * m;
        count--;

        dist[0][0] = 1;
        pq.push({1,0});

        while(count > 0){
            auto  [d,ind] = pq.top(); pq.pop();
            int i = ind / m;
            int j = ind % m;

            if (d > dist[i][j]){
                continue;
            }

            if(i == n-1 && j == m-1){
                return (dist[n-1][m-1] == INT_MAX ? -1 : dist[n-1][m-1]);
            }

            if(i == -1){
                return -1;
            }

            visited[i][j] = 1;
            count--;

            for (int dir = 0; dir < 8; ++dir) {
                int ni = i + dx[dir];
                int nj = j + dy[dir];

                // check bounds
                if (ni >= 0 && ni < n && nj >= 0 && nj < m) {
                    if (grid[ni][nj] == 0 && !visited[ni][nj]) {
                        if(dist[ni][nj] > dist[i][j] + 1){
                            dist[ni][nj] = dist[i][j] + 1;
                            pq.push({dist[i][j], ni * m + nj});
                        }
                    }
                }
            }
        }

        return (dist[n-1][m-1] == INT_MAX ? -1 : dist[n-1][m-1]);
    }
};
