//https://www.geeksforgeeks.org/problems/detect-cycle-in-an-undirected-graph/0
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  private:
    bool dfs(vector<int> adj[], vector<int> &visited, int node, int parent) {
        visited[node] = 1;
        for (auto j : adj[node]) {
            if (visited[j] == 0) {
                if (dfs(adj, visited, j, node)) {
                    return true;
                }
            } else if (j != parent) {
                return true;
            }
        }
        return false;
    }
    
  public:
    // Function to detect cycle in an undirected graph.
    bool isCycle(int V, vector<int> adj[]) {
        vector<int> visited(V, 0);
        for (int i = 0; i < V; i++) {
            if (visited[i] == 0) {
                if (dfs(adj, visited, i, -1)) {
                    return true;
                }
            }
        }
        return false;
    }
};


//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;
        bool ans = obj.isCycle(V, adj);
        if (ans)
            cout << "1\n";
        else
            cout << "0\n";
    }
    return 0;
}