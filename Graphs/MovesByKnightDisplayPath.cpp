#include<bits/stdc++.h>
using namespace std;
bool inRange(int x, int y, int N){
   return (x > 0 && y > 0 && x <= N && y <= N);
}
void printPath(vector<pair<int,int>> path){
   cout<<"Path taken by the knight will be:\n";
   for(int i = 0; i < path.size(); i++){
      cout<<path[i].first<<" "<<path[i].second<<"\n";
   }
}
int movesByKnight(int N, int kx, int ky, int tx, int ty){
   vector<vector<bool>> vis(N+1,vector<bool>(N+1,false));
   vector<pair<int,int>> directions = {{-2,1},{-2,-1},{2,-1},{2,1},{1,-2},{-1,-2},{1,2},{-1,2}};
   //queue<pair<pair<int,int>,int>> q;
   //q.push({{kx,ky},0});
   vis[kx][ky] = true;
   vector<pair<int,int>> path;
   path.push_back({kx,ky});
   queue<vector<pair<int,int>>> q;
   q.push(path);
   while(!q.empty()){
      path = q.front();
      pair<int,int> last = path.back();
      q.pop();
      if(last.first == tx && last.second == ty){
         printPath(path);
         return path.size()-1;
      }
      for(pair<int,int> dir: directions){
         int x = last.first+dir.first;
         int y = last.second+dir.second;
         if(inRange(x,y,N) && !vis[x][y]){
            vis[x][y] = true;
            vector<pair<int,int>> newPath(path);
            newPath.push_back({x,y});
            q.push(newPath);
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
      int ans = movesByKnight(N,kx,ky,tx,ty);
      cout<<"\nIt would reach the target in "<<ans<<" moves.\n";
}
