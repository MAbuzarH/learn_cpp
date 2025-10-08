#include <iostream>
using namespace std;

int main()
{
  int n, m;
  cout << "input N and M";
  cin >> n >> m;

  // it takes O(n) time
  // and n^2 space

  int adj[n + 1][n + 1];

  for (int i = 0; i < n + 1; i++)
  {
    for (int j = 0; j < n + 1; j++)
    {
      adj[i][j] = 0;
    }
  }

  // graph stored here
  for (int i = 0; i < m; i++)
  {
    int u, v;
    cout << "Enter edges between nodes:U && V:";
    cin >> u >> v;
    adj[u][v] = 1;
    adj[v][u] = 1;
  }

  cout << "graph out put \n";
  for (int i = 0; i < n + 1; i++)
  {
    for (int j = 0; j < n + 1; j++)
    {
      cout << "G[" << i << "]" << "[" << j << "]: " << adj[i][j] << endl;
    }
  }
  return 0;
}