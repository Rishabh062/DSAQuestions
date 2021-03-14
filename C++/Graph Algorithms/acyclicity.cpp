//#include <iostream>
//#include <vector>
//
//using std::vector;
//using std::pair;
//
//int dfs(vector<vector<int> > &adj, int x, vector<int> &visited, vector<int> &recStack) {
//  // Mark the current node as visited and part of recursion stack
//  visited[x] = 1;
//  recStack[x] = 1;
//  // Recur for all the vertices adjacent to this vertex
//  for (int i = 0; i < adj[x].size(); i++) {
//    if (!visited[adj[x][i]] && dfs(adj, adj[x][i], visited, recStack))
//	  return 1;
//	else if(recStack[adj[x][i]])
//	  return 1;
//  }
//  recStack[x] = 0;  // remove the vertex from recursion stack
//  return 0;
//}
//
//int acyclic(vector<vector<int> > &adj) {
//  // Mark all the vertices as not visited and not part of recursion stack
//  vector<int> visited(adj.size());
//  vector<int> recStack(adj.size());
//  for (int i = 0; i < adj.size(); i++)
//  {
//    if (!visited[i]) {
//      if (dfs(adj, i, visited, recStack)) 
//        return 1;
//    }
//  }
//  return 0;
//}
//
//int main() {
//  size_t n, m;
//  std::cin >> n >> m;
//  vector<vector<int> > adj(n, vector<int>());
//  for (size_t i = 0; i < m; i++) {
//    int x, y;
//    std::cin >> x >> y;
//    adj[x - 1].push_back(y - 1);
//  }
//  std::cout << acyclic(adj);
//}

#include<bits/stdc++.h>
using namespace std;

void addEdge(vector<vector<int>> &adj, int v,int w)
{
    adj[v].push_back(w);
    adj[w].push_back(v);
}

int dfs(vector<vector<int>> &adj,vector<int> &visited,vector<int> &recStack,int x)
{
    visited[x]=1;
    recStack[x]=1;

    for(int i=0;i<adj[x].size();i++)
    {
        if(!visited[adj[x][i]] && dfs(adj,visited,recStack,adj[x][i]))
        return 1;
        else if(recStack[adj[x][i]])
        return 1;
    }

    recStack[x]=0;
    return 0;
}

int acyclic(vector<vector<int>> &adj)
{
    vector<int> visited(adj.size());
    vector<int> recStack(adj.size());

    for(int i=0;i<adj.size();i++)
    {
        if(!visited[i])
        {
            if(dfs(adj,visited,recStack,i))
            return 1;
        }
    }
    return 0;

}



int main()
{
    int vertices,edges;
    cin>>vertices>>edges;

    vector<vector<int>> adj;

    for(int i=0;i<edges;i++)
    {
        int x,y;
        cin>>x>>y;
        addEdge(adj,x-1,y-1);
    }

    cout<<acyclic(adj)<<"\n";
}