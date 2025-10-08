
// space complexcity O(3n) = O(n)
// time complexcity O(n) + O(2E)
#include <iostream>
#include <vector>
#include <queue>

using namespace std;


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


void displyBfs(vector<int> bfs){

  for (int j = 0; j < bfs.size(); j++)
  {
    cout << bfs[j] << " ";
  }
  cout << endl;
}

vector<int> BFS(vector<int> adj[],int vis[]){
 queue<int> q;
  vector<int> bfs;

  vis[1] = 1; // mark first node as visited
  q.push(1);

  while (!q.empty())
  {

    int node = q.front();
    q.pop();
    bfs.push_back(node);

    for (auto it : adj[node])
    {
      if (!vis[it])
      {
        vis[it] = 1;
        q.push(it);
      }
    }
  }
  return bfs;
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
 
  vector<int> bfs = BFS(adj,vis);
  
  displyBfs(bfs);
  return 0;
}