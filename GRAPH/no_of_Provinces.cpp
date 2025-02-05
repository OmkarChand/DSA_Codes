#include<iostream>
#include<vector>

using namespace std;

// Undirected graph
void addEdges(vector<vector<int>> &adjls, int m) {
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adjls[u].push_back(v);
        adjls[v].push_back(u);
    }
}

void printGraph(vector<vector<int>> adjls, int n, int m) {
    cout << "Adj list of given Graph:" << endl;
    for (int i = 1; i <= n; i++) {
        cout << "Nodes connected to " << i << ": ";
        for (auto it: adjls[i]) {
            cout << it << " " ;
        }
        cout << endl;
    }
}

void dfs(int s, vector<vector<int>> &adjls, vector<int> &vis) {
    vis[s] = 1;
    for (auto it : adjls[s]) {
        if(!vis[it]) {
            dfs(it, adjls, vis);
        }
    }
}

// Space and Time of
// Space complexity = (space for vis[] array + recursion stack space worst case O(n))
//                  = O(n) + O(n) ~~ O(n)

// Time Complexity  = function will be called for each node once and each time for loop will run for degree of that selectd node
//                  we already know graphs total degree = 2*E or (2 * no of edges)
//                  = O(n) + O(2E) ---> Undirected Graph
//                  = O(n) + O(E)  ---> Directed Graph
void noOfProvinces(vector<vector<int>> &adjls, int n) {
    int cnt = 0;
    vector<int> vis (n+1, 0);
    for(int i = 1; i <= n; i++) {
        if(!vis[i]) {
            cnt++;
            dfs(i, adjls, vis);
        }
    }
    cout << "No. of provinces: " << cnt << endl;
}

int main() {
    int n, m;
    cout << "enter no of nodes and edges: ";
    cin >> n >> m;

    vector<vector<int>> adjls (n+1);
    cout << "enter edges : " << endl;
    addEdges(adjls, m);

    printGraph(adjls, n, m);

    noOfProvinces(adjls, n);

    return 0;
}