#include<iostream>
#include<vector>
using namespace std;

// Implementation using Array of vectors, you can use vector of vector as well
const int MAX_NODES = 100;
vector<int> adj[MAX_NODES];

int add_edges(int m){
    
    cout << "enter the edges: ";
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    return 0;
}

int printGraph(int n) {
    for (int i = 1; i <= n; i++) {
        cout << "adjacency list of node " << i << " is: ";
        for (auto it: adj[i]) {
            cout << it << " " ;
        }
        cout << endl;
    }
    return 0;
}

int main() {
    int n, m;
    cout << "enter number of nodes and edges (space seperated): ";
    cin >> n >> m;
    
    add_edges(m);
    printGraph(n);

    return 0;
}