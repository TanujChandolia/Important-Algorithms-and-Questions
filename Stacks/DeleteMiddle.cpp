#include<bits/stdc++.h>
using namespace std;

void deleteMid(stack<int> &s, int n, int current){
   if(current == 0)
      current = 1;

   if(current == ceil(n/2.0)){
      s.pop();
   }
   else{
      int x = s.top();
      s.pop();
      deleteMid(s , n , ++current);
      s.push(x);
   }
}
int main(){
   stack<int> s;
   int n; cin >> n;
   for(int i = 0; i < n; i++){
      int val; cin >> val;
      s.push(val);
   }
   deleteMid(s,s.size(),0);
   cout<<"stack: ";
   while(!s.empty()){
      cout<<s.top()<<" ";
      s.pop();
   }
}
