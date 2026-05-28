#include<iostream>
#include<vector>
#include<queue>
#include<string>
using namespace std;
    int  dfs(vector<vector<int>> &grid, vector<vector<bool>> &visited, int r, int c) {
            int rows = grid.size(), cols = grid[0].size();
    
            // If out of bounds, it's touching the border, not closed
            if (r < 0 || r >= rows || c < 0 || c >= cols) {
                return false;
            }
    
            // If water or alr this path is closeady visited,ed
            if (grid[r][c] == 1 || visited[r][c]) {
                return true;
            }
    
            visited[r][c] = true;
    
            // Check all directions, and use AND to ensure all parts are closed
            bool down = dfs(grid, visited, r + 1, c);
            bool up = dfs(grid, visited, r - 1, c);
            bool right = dfs(grid, visited, r, c + 1);
            bool left = dfs(grid, visited, r, c - 1);
    
            return down && up && right && left;
        }
        int numIslands(vector<vector<char>>& grid) {
            int rows = grid.size();
            int cols = grid[0].size();
            int totIsland = 0;
    
            vector<vector<bool>> visited(rows, vector<bool>(cols, false));
    
            for (int r = 0; r < rows; r++) {
                for (int c = 0; c < cols; c++) {
                    if (grid[r][c] == 1 && !visited[r][c]) {
                        if (dfs(grid[], visited, r, c)) {
                            totIsland++;
                        }
                    }
                }
            }
    
            return totIsland;
        }
 int main(){
    vector<vector<int>> grid[4] = {
        {"1","1","1","1","0"},
        {"1","1","0","1","0"},
        {"1","1","0","0","0"},
        {"0","0","0","0","0"}
    };
    return 0;
 }