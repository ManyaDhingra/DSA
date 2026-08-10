class Solution {
public:
    void dfs(int i , unordered_map<int , list<int>> &adj , unordered_map<int, bool> &visited, long long 
    &size){

        visited[i] = true;
        size++;
        for(auto neighbour : adj[i]){
            if(!visited[neighbour]){
                dfs(neighbour, adj , visited, size);
            }
        }

    }
    long long countPairs(int n, vector<vector<int>>& edges) {

        unordered_map<int , list<int>> adj;
        for(int i = 0 ; i < edges.size() ; i++){
            int u = edges[i][0];
            int v = edges[i][1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        unordered_map<int, bool> visited;

        long long ans = 0;
        long long prev = 0;

        for(int i = 0 ; i < n ; i++){
            if(!visited[i]){
                long long size = 0;
                dfs(i , adj, visited , size);

                ans += size*prev;
                prev += size;
            }
        }
        return ans;
        
    }
};