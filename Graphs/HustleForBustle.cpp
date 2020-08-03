#include<bits/stdc++.h>
using namespace std;

int main(){
   ios_base::sync_with_stdio(false);
   cin.tie(0);
   int N,M,K;
   cin >>N>>M>>K;

   priority_queue<pair<int,int> , vector<pair<int,int>>, greater<pair<int,int>>>pq;
   vector<int> dist(N+1,INT_MAX);
   vector<pair<int,int>> adj[N+1];

   for(int i = 0; i < M; i++){
      int school; cin >> school;
      pq.push({0,school});
      dist[school] = 0;
   }

   for(int i = 0; i < K; i++){
      int a,b,w;
      cin>>a>>b>>w;
      adj[a].push_back({b,w});
      adj[b].push_back({a,w});
   }

   while(!pq.empty()){
      pair<int,int> school = pq.top();
      pq.pop();
      for(pair<int,int> x : adj[school.second]){
         int sch = x.first;
         int w = x.second;
         if(dist[sch] > dist[school.second]+w){
            dist[sch] = dist[school.second]+w;
            pq.push({dist[sch],sch});
         }
      }
   }

   for(int i = 1; i < dist.size(); i++){
      if(dist[i] == INT_MAX)
         cout<<-1<<" ";
      else
         cout<<dist[i]<<" ";
   }
}
