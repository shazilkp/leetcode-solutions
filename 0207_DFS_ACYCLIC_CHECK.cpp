class Solution {
public:
    bool dfs(int i,vector<vector<int>>& graph,vector<int> &visited){
        visited[i] = 2;
        for(int j = 0; j < graph[i].size(); j++){

            if(visited[graph[i][j]] == 0){
                if(dfs(graph[i][j],graph,visited) == false){
                    return false;
                }
            }
            else if(visited[graph[i][j]] == 2){
                return false;
            }
        }

        visited[i] = 1;
        return true;
    }

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        //find if prereq graph is cyclic
        vector<int> visited(numCourses,0);
        vector<vector<int>> graph(numCourses,vector<int>());
        for(int i = 0 ; i < prerequisites.size() ; i++){
            graph[prerequisites[i][1]].push_back(prerequisites[i][0]);
        }

        for(int i = 0; i < numCourses; i++) {
            if(visited[i] == 0){
                if(dfs(i,graph,visited) == false){
                    return false;
                }
            }
        }
        return true;
    }
};
