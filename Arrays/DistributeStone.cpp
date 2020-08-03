#include<bits/stdc++.h>
using namespace std;

int minMoves(vector<int> stones){
   int n = stones.size();
   int req = 0, extra = 0, count = 0, res = 0;
   bool canStartCount = false;

   for(int i = 0; i < n; i++){
      if(canStartCount)
         count++;

      if(stones[i] == 0){
         req++;
         canStartCount = true;
      }
      if(stones[i] > 1){
         extra += stones[i]-1;
         canStartCount = true;
      }

      if(req > 0 && extra > 0){
         if(req == extra){
            req = 0; extra = 0;
            res += count;
            count = 0;
            canStartCount = false;
         }
        else if(req > extra){
           req -= extra;
           extra = 0;
        }
        else{
           extra -= req;
           req = 0;
        }
      }
   }

   return res;
}
int main(){
   int n; cin >> n;
   vector<int> stones(n);

   for(int i = 0; i < n; i++)
      cin >> stones[i];

   cout<<minMoves(stones);
}
