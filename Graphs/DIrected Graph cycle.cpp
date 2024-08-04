//https://www.geeksforgeeks.org/problems/detect-cycle-in-a-directed-graph/0
//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  private:
   bool dfs(int node , vector<int> adj[] , vector<int>& visited , vector<int>& pathvisited){
       visited[node] = 1 ;
       pathvisited[node] = 1 ;
        for(auto j : adj[node]) {
            if(!visited[j]) {
                if(dfs(j, adj, visited, pathvisited)) {
                    return true;
                }
            } else if(pathvisited[j]) {
                return true;
            }
        }
        
        pathvisited[node] = 0; // Reset the pathvisited for the node
        return false;
   }
  public:
    // Function to detect cycle in a directed graph.
    bool isCyclic(int V, vector<int> adj[]) {
        vector<int> visited(V , 0) ;
        vector<int> pathvisited(V , 0 ) ;
        for(int i = 0 ; i < V ; i++){
            if(visited[i] != 1) 
            if(dfs(i , adj , visited , pathvisited) == true ) return true ;
        }
        return false ;
    }
};


//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        cout << obj.isCyclic(V, adj) << "\n";
    }

    return 0;
}

// } Driver Code Ends