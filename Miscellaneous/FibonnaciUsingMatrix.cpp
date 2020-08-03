#include<bits/stdc++.h>
using namespace std;
int mod = 1e9 + 7;
void mul(int F[2][2] , int M[2][2]){
  int x =  F[0][0]*M[0][0] + F[0][1]*M[1][0];
  int y =  F[0][0]*M[0][1] + F[0][1]*M[1][1];
  int z =  F[1][0]*M[0][0] + F[1][1]*M[1][0];
  int w =  F[1][0]*M[0][1] + F[1][1]*M[1][1];

  F[0][0] = x;
  F[0][1] = y;
  F[1][0] = z;
  F[1][1] = w;
}
void power(int mat[2][2] , int p){
   if(p == 0 || p == 1)
      return;
   int M[2][2] = {{1,1} , {1,0}};
   power(mat, p/2);
   mul(mat,mat);
   if(p % 2 == 1)
      mul(mat,M);
}
int main(){
   int mat[2][2] = {{1,1} , {1,0}};
   int p; cin >> p;
   power(mat , p);

   for(int i = 0 ; i < 2; i++){
      for(int j = 0; j < 2; j++)
         cout<<mat[i][j]<<" ";
      cout<<"\n";
   }
}
