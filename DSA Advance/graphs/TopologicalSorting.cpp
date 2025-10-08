// Topological sorting
// ordring of vertices such that if there is an edge between U and V , U always appear before V in their ordring  this is applyable Directed Acyclic graph
// valid ordring :5 4 2 3 1 0;
// if adjancey matrix 5->0,4->0,5->2,2->3,3->1,4->1
// Why Direct Acyclic because U alwase come before
// cyclic dependency is also issue
// here is an example with dfs
#include <iostream>
#include <vector>
#include <queue>
#include <stack>

using namespace std;

void dfs(int node, int vis[], stack<int> &st, vector<int> adj[])
{
  vis[node] = 1;
  for (auto it : adj[node])
  {
    if (!vis[it])
    {
      dfs(it, vis, st, adj);
    }
  }
  st.push(node);
}

void displayAdjacency(vector<int> adj[], int n)
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

void dfsDisplay(vector<int> ls)
{
  printf("DFS result:");
  for (int node : ls)
  {
    cout << node << " ";
  }
  cout << endl;
}

vector<int> topoSort(int V, vector<int> adj[])
{
  int vis[V] = {0};
  stack<int> st;
  for (int i = 0; i < V; i++)
  {
    if (!vis[i])
    {
      dfs(i, vis, st, adj);
    }
  }
  vector<int> ans;
  while (!st.empty())
  {
    ans.push_back(st.top());
    st.pop();
  }
  return ans;
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
  }

  displayAdjacency(adj, n);

  vector<int> ls;
  ls = topoSort(m, adj);

  dfsDisplay(ls);
  return 0;
}