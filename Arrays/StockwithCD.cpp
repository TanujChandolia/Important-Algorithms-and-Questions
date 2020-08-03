#include<bits/stdc++.h>
using namespace std;
void printA(vector<int> a,vector<int> b){
   for(int x:a)
      cout<<x<<" ";
   cout<<"\n";
   for(int x:b)
      cout<<x<<" ";
   cout<<"\n";
   /*
   for(int x:c)
      cout<<x<<" ";
   */
   cout<<"\n\n";
}


int maxProfit(vector<int>& prices){
   if (prices.size() <= 1) return 0;
		vector<int> s0(prices.size(), 0);
		vector<int> s1(prices.size(), 0);
		//vector<int> s2(prices.size(), 0);
		s1[0] = -prices[0];
		s0[0] = 0;
		//s2[0] = -1;
		for (int i = 1; i < prices.size(); i++) {
         printA(s0,s1);

			s0[i] = max(s0[i - 1], s1[i - 1] + prices[i]);
			s1[i] = max(s1[i - 1], s0[i - 1] - prices[i]);

         printA(s0,s1);
		}
		return max(s0[prices.size() - 1], s1[prices.size() - 1]);
}
int main(){
   vector<int> prices = {100,50,45,80};
   cout<<maxProfit(prices);
}
