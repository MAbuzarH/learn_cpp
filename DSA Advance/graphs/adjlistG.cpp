#include <iostream>
#include <vector>
using namespace std;
int main()
{
  int n, m;
  cout << "input N and M";
  cin >> n >> m;
  vector<int> adj[n + 1];
  for (int i = 0; i < m; i++)
  {
    int u, v;
    cout << "Enter edges between nodes:U && V:";
    cin >> u >> v;
    adj[u].push_back(v);
    //if we have directed graph line 17 dont neded because
    // u ---> v only
    adj[v].push_back(u);
  }
}