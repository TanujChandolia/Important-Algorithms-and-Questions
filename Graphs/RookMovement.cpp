#include<bits/stdc++.h>
using namespace std;
bool valid(int x, int y, int N){
   return (x >= 0 && x < N && y >= 0 && y < N);
}
void printQ(queue<vector<int>> q){
   while(!q.empty()){
      vector<int> v = q.front();
      q.pop();
      for(int i:v)
         cout<<i<<" ";
      cout<<"\n";
   }
   cout<<"\n";
}
void rookMovement(vector<vector<int>> &grid){
      vector<vector<bool>> vis(5,vector<bool> (5,false));
      int tx = 4, ty = 4, turns;
      vector<pair<int,int>> directions = {{0,-1},{0,1},{-1,0},{1,0}};

      queue<vector<int>> q;
      vector<int> v = {0,0,-1,0}; //x y dir turns
      vis[0][0] = true;

      q.push(v);
      while(!q.empty()){
         //printQ(q);
         vector<int> curr = q.front();
         q.pop();
         if(curr[0] == tx && curr[1] == ty){
            turns = curr[3];
            break;
         }
         if(curr[2] == -1){
            for(int i = 0; i < 4; i++){
               int x = directions[i].first + curr[0];
               int y = directions[i].second + curr[1];
               if(valid(x,y,5) && grid[x][y] != 1 && vis[x][y] == false){
                  vis[x][y] = true;
                  vector<int> newV = {x,y,i,0};
                  q.push(newV);
               }
            }
         }

         else{
            for(int i = 0; i < 4; i++){
               int x = directions[i].first + curr[0];
               int y = directions[i].second + curr[1];
               if(valid(x,y,5) && grid[x][y] != 1 && vis[x][y] == false){
                  vis[x][y] = true;
                  vector<int> newV = {x,y,i,curr[3]};
                  if(i != curr[2])
                     newV[3]++;
                  q.push(newV);
               }
            }
         }
      }

      cout<<turns<<"\n";
}

int main(){
   vector<vector<int>> grid(5,vector<int> (5));
   for(int i = 0; i < 5; i++)
      for(int j = 0; j < 5; j++)
         cin >> grid[i][j];

   cout<<"\n";
   rookMovement(grid);
}

/*
-1 null
0 left
1 right
2 up
3 down
*/

/*
0 0 0 0 0
0 1 0 1 0
0 1 0 1 0
0 1 0 1 0
0 0 0 1 0
*/
