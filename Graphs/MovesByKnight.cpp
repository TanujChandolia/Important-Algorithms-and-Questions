#include<bits/stdc++.h>
using namespace std;
bool inRange(int x, int y, int N){
   return (x > 0 && y > 0 && x <= N && y <= N);
}
int movesByKnight(int N, int kx, int ky, int tx, int ty){
   vector<vector<bool>> vis(N+1,vector<bool>(N+1,false));
   vector<pair<int,int>> directions = {{-2,1},{-2,-1},{2,-1},{2,1},{1,-2},{-1,-2},{1,2},{-1,2}};
   queue<pair<pair<int,int>,int>> q;
   q.push({{kx,ky},0});
   vis[kx][ky] = true;

   while(!q.empty()){
      pair<pair<int,int>,int> p = q.front();
      q.pop();
      if(p.first.first == tx && p.first.second == ty)
         return p.second;
      for(pair<int,int> dir: directions){
         int x = p.first.first+dir.first;
         int y = p.first.second+dir.second;
         if(inRange(x,y,N) && !vis[x][y]){
            vis[x][y] = true;
            q.push({{x,y},p.second+1});
         }
      }
   }

   return -1;
}
int main(){
      int N;
      cout<<"Enter size of board: "; cin >> N;
      cout<<"Enter knight's position: ";
      int kx,ky; cin >>kx>>ky;
      cout<<"Enter target's position: ";
      int tx,ty; cin >>tx>>ty;

      cout<<"\nIt would reach the target in "<<movesByKnight(N,kx,ky,tx,ty)<<" moves.\n";
}
