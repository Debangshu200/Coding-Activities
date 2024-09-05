//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to detect cycle in an undirected graph.
     bool isCycle(int V, vector<int> adj[]) {
        queue<int> q;
        vector<int> parent(V);
        vector<int> visited(V, false);
        
        for(int i = 0; i<V; i++){
            if(!visited[i]){
                q.push(i);
                
                while(!q.empty()){
                int node = q.front();
                q.pop();
                visited[node] = true;
            
                for(auto &nbr : adj[node]){
                    if(!visited[nbr]){
                        parent[nbr] = node;
                        q.push(nbr);
                    }
                    else if(visited[nbr] && parent[node] != nbr){
                        return true;
                    }
                }
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
// } Driver Code Ends