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

// Space and Time of bfs_traversal function
// Space complexity = (space for bfs vector + vis[] array + queue space)
//                  = O(n) + O(n) + O(n) = O(3n) ~~ O(n)

// Time Complexity  = while loop runs for all nodes i.e. O(n) + for each node the for loop will run for selected nodes degree
//                  we already know graphs total degree = 2*E or (2 * no of edges)
//                  = O(n) + O(2E) ----> Undirected graph
//                  = O(n) + O(E)  ----> Directed graph
void bfs_traversal(vector<vector<int>> &adj, int n, int m) {
    int vis[n+1] = {0};
    vector<int> bfs;
    queue<int> q;
    int first;
    cout << "enter the first node: ";
    cin >> first;
    vis[first] = 1;
    q.push(first);

    while(!q.empty()) {
        int node = q.front();
        bfs.push_back(node);
        q.pop();
        for(auto it: adj[node]) {
            if (!vis[it]) {   // (vis[it] != 1)
               q.push(it);
               vis[it] = 1;
            }
        }
    }

    cout << "BFS traversal: ";
    for (auto it: bfs) {
        cout << it << " ";
    }
}

int main() {
    int n, m;
    cout << "enter no of nodes and edges (n & m): ";
    cin >> n >> m;

    vector<vector<int>> adj(n+1); // n+1 to hjandle 1 based indexing
    addEdges(adj, m);

    print(adj, n);

    bfs_traversal(adj, n, m);
    
    return 0;
}