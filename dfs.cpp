// DFS(Depth first search) : Based on recursion because we need to get into depth

#include<iostream>
#include<vector>
#include<queue>

using namespace std;

void addEdges (vector<vector<int>> &adj, int m) {
    cout << "enter edges: " << endl;
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
}

void print(vector<vector<int>> &adj, int n) {
    cout << "graph representation using adjacency list: " << endl;
    for(int i = 1; i <= n; i++) {
        cout << "node " << i << ": ";
        for(auto it: adj[i]) {
            cout << it << " ";
        }
        cout << endl;
    }
}

// Space and Time of dfs_traversal function
// Space complexity = (space for vis[] array + recursion stack space worst case O(n))
//                  = O(n) + O(n) ~~ O(n)

// Time Complexity  = function will be called for each node once and each time for loop will run for degree of that selectd node
//                  we already know graphs total degree = 2*E or (2 * no of edges)
//                  = O(n) + O(2E) ---> Undirected Graph
//                  = O(n) + O(E)  ---> Directed Graph
void dfs_traversal(vector<vector<int>> &adj, vector<int> &vis, int s) {
    vis[s] = 1;
    for(auto it: adj[s]) {
        if (!vis[it]) {   // (vis[it] != 1)
            cout << it << " ";
            dfs_traversal(adj, vis, it);
        }
    }
}

int main() {
    int n, m;
    cout << "enter no of nodes and edges (n & m): ";
    cin >> n >> m;
    vector<int> vis (n+1, 0);

    vector<vector<int>> adj(n+1); // n+1 to hjandle 1 based indexing
    addEdges(adj, m);

    print(adj, n);
    int start;
    cout << "Enter starting node for DFS traversal: ";
    cin >> start;
    cout << "DFS Traversal: " << start << " ";
    dfs_traversal(adj, vis, start);
    
    return 0;
}