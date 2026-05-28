#include <iostream>
#include <vector>
#include<queue>
#include <climits>  // For INT_MAX
using namespace std;

        int orangesRotting(vector<vector<int>>& grid,vector<vector<int> &vis) {
            int rows = grid.size();
            int cols = grid[0].size();
            queue<pair<int, int>,int> q;
            int fresh = 0;
    
            // Step 1: Count fresh oranges and push rotten oranges into queue
            for (int r = 0; r < rows; r++) {
                for (int c = 0; c < cols; c++) {
                    if (grid[r][c] == 2) {
                        q.push({r, c},0);
                    }else if(grid[r][c] == 1) fresh++;                    }
                }
            }
            int timer =0;
            int dr[] ={-1,+1,0,0};
            int dc[] ={0,0,+1,-1};
    
            while(!q.empty() ){
                int r = q.front().first.first;
                int c = q.front().first.second;
                int t = q.front().second;
                q.pop();
    
                for(int i=0; i<4; i++){
                    int nrow = r + dr[i];
                    int dcol= c + dc[i];
                    if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && vis[nrow][ncol] !=2 && if(grid[nrow][ncol]==1)){
                        grid[nrow][ncol] = 2;
                        fresh--;
                        q.push({nrow, ncol}, d+1);
                        timer = d+1;
    
                    }
                }
            }i
      
        
    