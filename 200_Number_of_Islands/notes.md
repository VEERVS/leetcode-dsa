## Problem
Given an `m x n` 2D binary grid consisting of `'1'` (land) and `'0'` (water), return the number of islands.

An island is formed by connecting adjacent land cells horizontally or vertically. Cells connected diagonally are not considered part of the same island.

**LeetCode:** 200. Number of Islands

## My Approach
I used Depth-First Search (DFS) to explore connected land cells.

I traversed the entire grid using two nested loops. Whenever I encountered an unvisited land cell (`'1'`), I incremented the island count and started DFS from that cell.

The DFS explored all four possible directions:
- Down
- Up
- Right
- Left

To avoid visiting the same land cell multiple times, I marked each visited cell as water (`'0'`).

Once DFS finished, the entire connected island had been visited. The outer traversal continued to find any remaining islands.

## Key Logic
1. Check whether the grid is empty and return `0` if it is.
2. Traverse every cell using nested loops.
3. If `grid[i][j] == '1'`:
   - Increment the island count.
   - Call DFS from that cell.
4. In DFS:
   - Check boundaries and whether the current cell is land.
   - Return if the cell is out of bounds or water.
   - Mark the current cell as visited by changing it to `'0'`.
   - Recursively explore all four adjacent directions.
5. Return the total island count.

## Solution
```cpp
class Solution {
public:
    void DFS(vector<vector<char>>& grid, int r, int c) {
        int rows = grid.size();
        int cols = grid[0].size();

        if (r < 0 || c < 0 || r >= rows ||
            c >= cols || grid[r][c] == '0') {
            return;
        }

        grid[r][c] = '0';

        DFS(grid, r + 1, c);
        DFS(grid, r - 1, c);
        DFS(grid, r, c + 1);
        DFS(grid, r, c - 1);
    }

    int numIslands(vector<vector<char>>& grid) {
        if (grid.empty() || grid[0].empty()) return 0;

        int rows = grid.size();
        int cols = grid[0].size();
        int island = 0;

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (grid[i][j] == '1') {
                    island++;
                    DFS(grid, i, j);
                }
            }
        }

        return island;
    }
};
```

## Complexity
- **Time Complexity:** `O(m * n)` — every cell is visited at most once.
- **Space Complexity:** `O(m * n)` — in the worst case, the recursive DFS call stack can contain up to `m * n` cells.

## What I Learned
- DFS can be used to explore connected components in a 2D grid.
- Every new unvisited land cell represents a new island.
- Marking visited cells prevents repeated traversal.
- A grid cell has four possible adjacent directions: up, down, left, and right.
- Boundary checks prevent accessing invalid grid positions.
- The same DFS pattern can solve connected-component and grid traversal problems.