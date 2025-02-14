#include<iostream>
#include<vector>
#include<queue>

using namespace std;

void bfs(int row, int col, vector<vector<char>>& grid, vector<vector<int>>& vis) {
    vis[row][col] = 1;
    queue<pair<int,int>> q;
    q.push({row, col});
    int n = grid.size();
    int m = grid[0].size();

    while(!q.empty()) {
        int row = q.front().first;
        int col = q.front().second;
        q.pop();

        // traverse the neighbours and mark them if its a land
        // delrow / delcol -> delta row/column 
        // nrow / ncol--> neighbour row/col
        for(int delrow = -1; delrow <= 1; delrow++) {
            for(int delcol = -1; delcol <= 1; delcol++) {
                int nrow = row + delrow;
                int ncol = col + delcol;

                if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < m 
                    && grid[nrow][ncol] == '1' && !vis[nrow][ncol]) {
                        vis[nrow][ncol] = 1;
                        q.push({nrow, ncol});
                }
            }
        }
    }
    
}

// No of Islands or Connected component
// Note: Input is given in the form of 2d matrix and 
// from the node you can travel the neighbours diagonally, vertically and horizontly
void numIslands(vector<vector<char>>& grid) {
    int n = grid.size();
    int m = grid[0].size();
    vector<vector<int>> vis(n, vector<int>(m, 0));
    int cnt = 0;

    for(int row = 0; row < n; row++) {
        for(int col = 0; col < m; col++) {
            if(!vis[row][col] && grid[row][col] == '1') {
                cnt++;
                bfs(row, col, grid, vis);
            }
        }
    }
    cout << "Number of Islands/Connected components = " << cnt << endl;
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

    // Space complexity : SC = space for vis array + queue space
    //                       = O(n^2) + O(n^2)
    //                       = O(n^2)

    // Time complexity : TC = for matrix inorder to check for land ('1') + number of time you calls bfs worst case when all are lands
    //                      = O(n^2) + O(n^2)*9
    //                      = O(n^2)
    numIslands(grid);

    // cout << "Print the grid: " << endl;
    // for(int i = 0; i < n; i++) {
    //     for(int j = 0; j < m; j++) {
    //         cout << grid[i][j] << " ";
    //     }
    //     cout << endl;
    // }    
}