#include<iostream>

using namespace std;
int squareRoot(int num)
{
   if(num == 0 || num == 1)
      return num;
   int start = 1 , end = num,ans;
   while(start <= end)
      {
         int mid = (start + end)/2;
         if(mid*mid == num)
            return mid;
         if(mid*mid < num)
            {
               start = mid + 1;
               ans = mid;
            }
         else
            end = mid - 1;
      }
   return ans;
}
int main()
{
   int num = 100;
   cout<<squareRoot(num);
   return 0;
}
