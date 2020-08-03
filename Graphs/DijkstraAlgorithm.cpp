#include<bits/stdc++.h>
using namespace std;

void addEdge(vector<pair<int,int>> adj[], int u, int v, int w){
   adj[u].push_back({v,w});
   adj[v].push_back({u,w});
}

void printDistances(vector<int> dist, vector<int> parent){
   cout<<"Route                 Distance                 Path\n";
   for(int i = 0; i < dist.size(); i++){
      cout<<"0 -> "<<i<<"                 "<<dist[i]<<"                      ";
      if(dist[i])
         cout<<setw(2-floor(log10(dist[i])));
      else
         cout<<" ";
      int x = i;
      while(x >= 0){
         cout<<x;
         if(x != 0)
            cout<<" <- ";
         x = parent[x];
      }
      cout<<"\n";
   }
}
void dijkstraAlgo(vector<pair<int,int>> adj[], int V,int src){
   priority_queue<pair<int,int> , vector<pair<int,int>>, greater<pair<int,int>>> pq;
   vector<int> dist(V,INT_MAX);
   vector<int> parent(V,-1);
   pq.push({0,src});
   dist[src] = 0;

   while(!pq.empty()){
      int u = pq.top().second;
      pq.pop();

      for(pair<int,int> x : adj[u]){
         int v = x.first;
         int weight = x.second;
         if(dist[v] > dist[u]+weight){
            dist[v] = dist[u]+weight;
            parent[v] = u;
            pq.push({dist[v],v});
         }
      }
   }

   printDistances(dist,parent);
}
int main(){
   int V = 5;
   vector<pair<int,int>> adj[V];
   addEdge(adj,0,1,5);
   addEdge(adj,0,4,9);
   addEdge(adj,1,4,20);
   addEdge(adj,1,2,10);
   addEdge(adj,2,3,5);
   addEdge(adj,2,4,10);
   addEdge(adj,3,4,8);

   dijkstraAlgo(adj,V,0);
}
