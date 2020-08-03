#include<bits/stdc++.h>
using namespace std;
void addEdge(vector<pair<int,int>> adj[], int u, int v, int w){
   adj[u].push_back({v,w});
   adj[v].push_back({u,w});
}
void printGraph(vector<int> parent){
   cout<<"Node      Parent\n";
   for(int i = 0; i < parent.size(); i++)
      cout<<i<<"           "<<parent[i]<<"\n";
}
void PrimMST(vector<pair<int,int>> adj[], int V){
   vector<bool> mstSet(V,false);
   vector<int> key(V,INT_MAX);
   vector<int> parent(V,-1);

   key[0] = 0;
   priority_queue<pair<int,int>, vector<pair<int,int>> , greater<pair<int,int>>> pq;
   pq.push({0,0});

   while(!pq.empty()){
      pair<int,int> p = pq.top();
      mstSet[p.second] = true;
      pq.pop();
      for(pair<int,int> x:adj[p.second]){
         int u = x.first;
         int w = x.second;
         if(mstSet[u] == false && key[u] > w){
            key[u] = w;
            pq.push({key[u],u});
            parent[u] = p.second;
         }
      }
   }

   printGraph(parent);
}
int main(){
   int V = 9;
   vector<pair<int,int>> adj[V];
   addEdge(adj,0,1,4);
   addEdge(adj,0,7,8);
   addEdge(adj,1,7,11);
   addEdge(adj,1,2,8);
   addEdge(adj,7,8,7);
   addEdge(adj,7,6,1);
   addEdge(adj,6,8,6);
   addEdge(adj,6,5,2);
   addEdge(adj,5,2,4);
   addEdge(adj,2,8,2);
   addEdge(adj,2,3,7);
   addEdge(adj,3,4,8);
   addEdge(adj,3,5,14);
   addEdge(adj,4,5,10);

   PrimMST(adj,V);
}
