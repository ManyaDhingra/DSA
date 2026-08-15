class Solution {
public:
    bool dfs(int node, unordered_map<int, bool> &visited , unordered_map<int, bool> &dfsvisited, unordered_map<int, list<int>> &adj){
        visited[node] = true;
        dfsvisited[node] = true;
        for(auto neighbour : adj[node]){
            if(!visited[neighbour]){
                bool cycle = dfs(neighbour, visited, dfsvisited, adj);
                if(cycle){
                    return true;
                }
            }
            else if(dfsvisited[neighbour]){
                return true;
            }
        }
        dfsvisited[node] = false;
        return false;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int, list<int>> adj;
        unordered_map<int, bool> visited;
        unordered_map<int, bool> dfsvisited;

      

        for(int i = 0 ; i < prerequisites.size() ; i++){
            int u = prerequisites[i][0];
            int v = prerequisites[i][1];

            adj[v].push_back(u);
        }

        for(int i = 0 ; i < numCourses ; i++){
            if(!visited[i]){
                bool cycle = dfs(i , visited, dfsvisited, adj);
                if(cycle){
                    return false;
                }

            }
        }
        return true;
    }
};