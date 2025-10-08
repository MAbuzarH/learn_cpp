
// space complexcity O(3n) = O(n)
// time complexcity O(n) + O(2E)
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

void dfs(int node, vector<int> adj[], int vis[])
{
  vis[node] = 1;
  for (int it : adj[node])
  {
    if (!vis[it])
    {
      dfs(it, adj, vis);
    }
  }
}

void DisplayAdjList(vector<int> adj[], int n)
{
  cout << "\nAdjacency List:\n";
  for (int i = 1; i <= n; i++)
  {
    cout << i << " -> ";
    for (int node : adj[i])
    {
      cout << node << " ";
    }
    cout << endl;
  }
}

int main()
{
  int n, m;

  cout << "input N and M: ";

  cin >> n >> m;
  int vis[n + 1] = {0};

  vector<int> adj[n + 1];

  for (int i = 0; i < m; i++)
  {
    int u, v;

    cout << "Enter edges between nodes:U && V:";
    cin >> u >> v;

    adj[u].push_back(v);
    // if we have directed graph line 17 dont neded because
    //  u ---> v only
    adj[v].push_back(u);
  }

  DisplayAdjList(adj, n);

  int count = 0;
  for (int i = 1; i < n; i++)
  {
    if (!vis[i])
    {
      dfs(i, adj, vis);
      count++;
    }
  }

  cout << "Provinces are: " << count << endl;
  return 0;
}