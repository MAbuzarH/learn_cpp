
// space complexcity O(3n) = O(n)
// time complexcity O(n) + O(2E)
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

void dfs(int node, vector<int> adj[], int vis[], vector<int> &ls)
{
  vis[node] = 1;
  ls.push_back(node);
  for (auto it : adj[node])
  {
    if (!vis[it])
    {
      dfs(it, adj, vis, ls);
    }
  }
}

void displayAdjacency(vector<int>adj[],int n){
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

void dfsDisplay(vector<int>ls){
    printf("DFS result:");
  for (int node : ls)
  {
    cout << node << " ";
  }
  cout << endl;
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


  displayAdjacency(adj,n);

  vector<int> ls;
  int start = 2;

  dfs(start, adj, vis, ls);

  dfsDisplay(ls);
  return 0;
}