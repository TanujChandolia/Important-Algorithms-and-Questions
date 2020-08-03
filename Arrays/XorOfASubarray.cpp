#include<bits/stdc++.h>
using namespace std;
void preprocess(int arr[] , int n , vector<vector<int>> &count){

	for(int i = 0; i < 32; i++){
		count[i][0] = 0;
		for(int j = 0; j < n; j++){
			if(j > 0){
				count[i][j] = count[i][j-1];
			}
			if(arr[j] & (1 << i) )
				count[i][j] ++;
		}
	}
}
int findXor(int l , int r, vector<vector<int>>count){
	int ans = 0;
	inta noOfOnes = 0;

	for(int i = 0; i < 32; i++){
		noOfOnes = count[i][r] - ((l > 0)? count[i][l]: 0);
		if (noOfOnes&1)
			ans += (1 << i);
	}
	return ans;
}
int main(){
	int n; cin >>n;
	int arr[n];
	for(int i = 0; i < n; i++)
		cin >> arr[i];
	vector<vector<int> > count (32 , vector<int>(n));
	preprocess(arr , n, count);
	int l , r;
	cin >> l >> r;

	cout<<findXor(l , r , count);
}
