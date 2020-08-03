#include<bits/stdc++.h>
using namespace std;

int Castle(vector<vector<char>> &grid, int sx, int sy, int gx, int gy){
   int N = grid.size();
   vector<vector<bool>> vis(N,vector<bool>(N,false));
   vector<int> state = {sx,sy,0};
   queue<vector<int>> q;
   q.push(state);

   vis[sx][sy] = true;

   while(!q.empty()){
      state = q.front();
      q.pop();
      if(state[0] == gx && state[1] == gy)
         return state[2];

      for(int i = state[1]+1; i < N; i++){
         if(grid[state[0]][i] == 'X')
            break;
         if(!vis[state[0]][i]){
            vis[state[0]][i] = true;
            vector<int> newState = {state[0],i,state[2]+1};
            q.push(newState);
         }
      }

      for(int i = state[1]-1; i >= 0; i--){
         if(grid[state[0]][i] == 'X')
            break;
         if(!vis[state[0]][i]){
            vis[state[0]][i] = true;
            vector<int> newState = {state[0],i,state[2]+1};
            q.push(newState);
         }
      }

      for(int i = state[0]+1; i < N; i++){
         if(grid[i][state[1]] == 'X')
            break;
         if(!vis[i][state[1]]){
            vis[i][state[1]] = true;
            vector<int> newState = {i,state[1],state[2]+1};
            q.push(newState);
         }
      }
      for(int i = state[0]-1; i >= 0; i--){
         if(grid[i][state[1]] == 'X')
            break;
         if(!vis[i][state[1]]){
            vis[i][state[1]] = true;
            vector<int> newState = {i,state[1],state[2]+1};
            q.push(newState);
         }
      }
   }

   return -1;
}
int main(){
   int N; cin >> N;
   vector<vector<char>> grid(N,vector<char>(N));
   for(int i = 0; i < N; i++)
      for(int j = 0; j < N; j++)
         cin >> grid[i][j];

   int sx,sy,gx,gy;
   cin >> sx >> sy >> gx >> gy;
   cout<<Castle(grid,sx,sy,gx,gy);
}

/*
5
. . . . .
X X . . .
. . . X X
. . . . .
. . . X .
4 0 4 4
*/
