#include<iostream>

using namespace std;

void matrixBeautify(int mat[][3] , int n)
{
   int row_sum[n] = {0}, col_sum[n] = {0};
   for(int  i = 0; i < n; i++)
   {
      for(int j = 0; j < n; j++)
      {
         row_sum[i] += mat[i][j];
         col_sum[j] += mat[i][j];
      }
   }

   int maxval = 0;
   for(int i = 0; i < n; i++)
   {
      maxval = max(row_sum[i],maxval);
      maxval = max(col_sum[i],maxval);
   }

   int diff = 0;
   int count = 0;
   for(int i = 0, j = 0; i < n && j < n;)
   {
         diff = min(maxval - row_sum[i] , maxval - col_sum[j]);

         mat[i][j] += diff;
         row_sum[i] += diff;
         col_sum[j] += diff;
         count += diff;

         if(row_sum[i] == maxval)
            i++;
         if(col_sum[j] == maxval)
            j++;
   }


}
int main()
{
   int n = 3;
   int mat[3][3] = { {1,2,3},
                     {3,4,1},
                     {2,5,6}
                  };

   matrixBeautify(mat , n);
   for(int i = 0; i < n; i++)
      {
         for(int j = 0; j < n; j++)
            cout<<mat[i][j]<<" ";
         cout<<endl;
      }
}
