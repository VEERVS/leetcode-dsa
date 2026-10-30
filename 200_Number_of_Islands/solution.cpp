class Solution {
public:
    void DFS(vector<vector<char>>& grid, int r, int c){
        int rows = grid.size();
        int cols = grid[0].size();

        if(r<0 || c<0 || r>=rows || c>=cols || grid[r][c]=='0') return;
        grid[r][c] = '0';

        DFS(grid, r+1, c);
        DFS(grid, r-1, c);
        DFS(grid, r, c+1);
        DFS(grid, r, c-1);
    }
    int numIslands(vector<vector<char>>& grid) {
        if (grid.empty() || grid[0].empty()) return 0;
        int rows = grid.size();
        int cols = grid[0].size();
        int island = 0;

        for(int i=0; i<rows; i++){
            for(int j=0; j<cols; j++){
                if(grid[i][j] == '1'){
                    island++;
                    DFS(grid, i, j);
                }
            }
        }
        return island;
    }

};