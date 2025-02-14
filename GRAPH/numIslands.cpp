#include<iostream>
#include<vector>

using namespace std;

void dfs(int row, int col, vect0r<vector<chat>>& grid, vector<vector<int>>& vis) {
    stack<pair<int,int>>> st;
    
}

// No of Islands or Connected component
// Note: Input is given in the form of 2d matrix and from one node you can travel diagonally, vertically and horizontly
void numIslands(vector<vector<char>>& grid) {
    int n = grid.size();
    int m = grid[0].size();
    vector<vector<int>> vis(n, vector<int>(m, 0));
    int cnt = 0;

    for(int row = 0; row < n; row++) {
        for(int col = 0; col < m; col++) {
            if(!vis[row][col]) {
                cnt++;
                dfs(row, col, grid, vis);
            }
        }
    }
    cout << "Number of Islands/Connected components = " << cnt;
}

int main() {
    int n, m;
    cout << "enter vlaue of Rows (n) and Columns (m): ";
    cin >> n >> m;

    vector<vector<char>> grid(n, vector<char> (m,0));
    cout << "Enter value of the grid (RMO)" << endl;
    
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> grid[i][j];
        }
    }

    numIslands(grid);

    // cout << "Print the grid: " << endl;
    // for(int i = 0; i < n; i++) {
    //     for(int j = 0; j < m; j++) {
    //         cout << grid[i][j] << " ";
    //     }
    //     cout << endl;
    // }    
}