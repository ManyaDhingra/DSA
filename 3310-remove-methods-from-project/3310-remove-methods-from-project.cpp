class Solution {
public:
    void dfs(vector<vector<int>> &adj, int node, vector<bool> & sus){
        sus[node] = true;
        for(int &a : adj[node]){
            if(!sus[a]){
                dfs(adj , a , sus);
            }
        }
    }
    vector<int> remainingMethods(int n, int k, vector<vector<int>>& invocations) {
        vector<vector<int>> adj(n);
        for(auto &i : invocations){
            adj[i[0]].push_back(i[1]);
        }

        vector<bool> sus(n, false);
        dfs(adj, k , sus);

        for(auto &i : invocations){
            int u = i[0];
            int v = i[1];

            if(!sus[u] && sus[v]){
                vector<int> ans;
                for(int i = 0 ; i < n ; i++){
                    ans.push_back(i);
                }
                return ans;
            }
        }
        vector<int> ans;

        for(int i = 0 ; i < n ; i++){
            if(!sus[i]){
                ans.push_back(i);
            }
        }


        return ans;



    }
};