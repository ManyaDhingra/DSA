class Solution {
  public:
    bool dfs(int node, unordered_map<int, list<int>> &adj, unordered_map<int, bool> &visited, unordered_map<int, bool> &dfsvisited, vector<int> &ans){
        visited[node] = true;
        dfsvisited[node] = true;
        for(auto neigh : adj[node]){
            if(!visited[neigh]){
                bool cycle = dfs(neigh, adj, visited, dfsvisited, ans);
                if(cycle){
                    return true;
                }
            }
            else if(dfsvisited[neigh]){
                return true;
            }
        }
        dfsvisited[node] = false;
        ans.push_back(node);
        return false;
    }
    vector<int> findOrder(int n, vector<vector<int>> &prerequisites) {
        // code here
        unordered_map<int, list<int>> adj;
        unordered_map<int, bool> visited;
        unordered_map<int, bool> dfsvisited;
        vector<int> ans;
        
        for(int i = 0 ; i < prerequisites.size() ; i++){
            int u = prerequisites[i][0];
            int v = prerequisites[i][1];
            
            adj[v].push_back(u);
        }
        
        for(int i = 0 ; i < n ; i++){
            if(!visited[i]){
                bool cycle = dfs(i, adj, visited, dfsvisited, ans);
                if(cycle){
                    return {};
                }
            }
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};