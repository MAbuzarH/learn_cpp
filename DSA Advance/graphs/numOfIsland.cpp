
// space complexcity O(3n) = O(n)
// time complexcity O(n) + O(2E)
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

void bfs(int row, int col, vector<vector<int>> &vis, vector<vector<char>> &grid)
{
  vis[row][col] = 1;
  queue<pair<int, int>> q;
  q.push({row, col});
  int n = grid.size();
  int m = grid[0].size();
  while (!q.empty())
  {
    int r = q.front().first;
    int c = q.front().second;
    q.pop();
    for (int delrow = -1; delrow <= 1; delrow++)
    {
      for (int delcol = -1; delcol <= 1; delcol++)
      {
        int nrow = r + delrow;
        int ncol = c + delcol;
        // check for velididty and and land and not visited
        if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m &&
            grid[nrow][ncol] == '1' && !vis[nrow][ncol])
        {
          vis[nrow][ncol] = 1;
          q.push({nrow, ncol});
        }
      }
    }
  }
}

int numberOfIsland(vector<vector<char>> &grid)
{
  int r = grid.size();
  int c = grid[0].size();
  vector<vector<int>> vis(r, vector<int>(c, 0));
  int count = 0;
  for (int row = 0; row < r; row++)
  {
    for (int col = 0; col < c; col++)
    {
      if (!vis[row][col] && grid[row][col] == '1')
      {
        count++;
        bfs(row, col, vis, grid);
      }
    }
  }
  return count;
}

int main()
{

  vector<vector<char>> grid = {
      {'0', '1', '1', '0'},
      {'0', '1', '1', '0'},
      {'0', '0', '1', '0'},
      {'0', '0', '0', '0'},
      {'1', '1', '0', '1'}};
  int result = numberOfIsland(grid);
  cout << "result is:" << result;
  // display Adjacency list
  // Display(adj, n);

  // apply bread first search
  // BFS(n, adj);

  return 0;
}