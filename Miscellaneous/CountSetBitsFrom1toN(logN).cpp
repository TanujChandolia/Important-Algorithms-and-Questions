#include<bits/stdc++.h>
using namespace std;

int countSetbits(int n){
   n++;
   int count = n/2;
   int pow = 2;

   while(pow <= n){
      int totalpairs = n/pow;
      int setpairs = totalpairs/2;
      int setbits = setpairs*pow;
      if(n%pow)
         setbits += n%pow;
      count += setbits;
      pow <<= 1;
   }
   return count;
   
}
int main(){
   int n; cin >> n;
   cout<<countSetbits(n);
}
