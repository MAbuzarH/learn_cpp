// kahn's algorithm
//  topological sort using BFS
// we can take an array having incoming edges info
// take a Queue insert a node that in degree is 0
// after that remove a node from queue and see who's incomming edge is poped elemen eg 4 is poped and 4 is incomming edge for 0 and 1 so from array decres incomming edge from 0 and 1 do this again and nodes in degre become 0  and you enqueue and dequeue
// to find indegree we trivers adjancency list and increas that index by 1;

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

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

void displyBfs(vector<int> bfs)
{

  for (int j = 0; j < bfs.size(); j++)
  {
    cout << bfs[j] << " ";
  }
  cout << endl;
}

vector<int> topoSort(int V, vector<int> adj[])
{
  vector<int> indegree(V, 0);
  // calculating the number of incomming edges
  for (int i = 0; i < V; i++)
  {
    for (auto it : adj[i])
    {
      indegree[it]++;
    }
  }

  queue<int> q;
  for (int i = 0; i < V; i++)
  {
    if (indegree[i] == 0)
      q.push(i);
  }

  vector<int> topo;
  while (!q.empty())
  {
    int node = q.front();
    q.pop();
    topo.push_back(node);
    // when node is in topo sort we have to remove its in degree
    for (auto it : adj[node])
    {
      indegree[it]--;
      if (indegree[it] == 0)
        q.push(it);
    }
  }

  return topo;
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

  vector<int> bfs = topoSort(n, adj);

  displyBfs(bfs);
  return 0;
}