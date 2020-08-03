#include<iostream>
using namespace std;
void getcofactor(int mat[3][3], int temp[3][3],int p,int q, int n)
{
   cout<<"Matrix: \n";
   for(int i = 0; i < n; i++)
   {
      for(int j = 0; j < n; j++)
         cout<<mat[i][j]<<" ";
      cout<<endl;
   }
   int i = 0, j = 0;
   for(int row = 0; row < n; row++)
   {
      for(int col = 0; col < n; col++)
      {
         if(row != p && col != q)
         {
            temp[i][j++] = mat[row][col];
            if(j == n-1)
            {
               j = 0;
               i++;
            }
         }
      }
   }
   cout<<"Temp: \n";
   for(int i = 0; i < n-1; i++)
   {
      for(int j = 0; j < n-1; j++)
         cout<<temp[i][j]<<" ";
      cout<<endl;
   }
}
int determinant(int mat[3][3] , int n)
{
   if(n == 1)
      return mat[0][0];
   int d = 0;
   int sign = 1;
   int temp[3][3];

   for(int f = 0; f < n; f++)
   {
      getcofactor(mat, temp , 0, f , n);
      d += sign*mat[0][f]* determinant(temp , n-1);
      sign = -sign;
      cout<<"D: "<<d<<endl;
   }
   return d;
}
int main()
{
   int n = 3;
   int mat[3][3] = {{1,2,3},
                    {4,2,1},
                    {5,1,2}
                   };
   cout<<determinant(mat , n);
   return 0;
}
