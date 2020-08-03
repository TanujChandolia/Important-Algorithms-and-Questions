#include<bits/stdc++.h>
using namespace std;
void addEdge(vector<int> adj[] ,int u,int v){
   adj[u].push_back(v);
   adj[v].push_back(u);
}

void dfs(vector<int> adj[],vector<bool>&vis,vector<int>&disc, vector<int>&low, vector<int>&parent, vector<bool>&ap, int u){
   static int time = 0;
   vis[u] = true;
   disc[u] = low[u] = ++time;
   int children = 0;
   for(int v : adj[u]){
      if(!vis[v]){
          children++;
          parent[v] = u;
          dfs(adj,vis,disc,low,parent,ap,v);

          low[u] = min(low[u],low[v]);                     // condition for articulation Points
          if(parent[u] == -1 && children > 1)
               ap[u] = true;
          if(parent[u] != -1 && low[v] >= disc[u]){
             ap[u] = true;
          }
          if(low[v] > disc[u])                  //condition for bridge edges
               cout<<u<<"<-->"<<v<<endl;

      }
      else if(v != parent[u]){
         low[u] = min(low[u],disc[v]);
      }
   }
}
void articulationPoints(vector<int> adj[], int V){
   vector<bool> vis(V,false);
   vector<int> disc(V,0);
   vector<int> low(V,0);
   vector<int> parent(V,-1);
   vector<bool> ap(V,false);

   cout<<"Bridges Edges are:\n";
   for(int i = 0; i < V; i++){
      if(!vis[i]){
         dfs(adj,vis,disc,low,parent,ap,i);
      }
   }

   cout<<"Articulation Points are: \n";
   for(int i = 0; i < V; i++)
      if(ap[i])
         cout<<i<<"\n";
}
int main(){
   int V = 5;
   vector<int> adj[V];
   addEdge(adj,0,1);
   addEdge(adj,0,2);
   addEdge(adj,0,3);
   addEdge(adj,1,2);
   addEdge(adj,3,4);

   //      1 ----- 2
   //    /        /
   //  0 --------/
   //    \
   //     3----- 4

   articulationPoints(adj,V);
}
