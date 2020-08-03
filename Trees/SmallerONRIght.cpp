#include<bits/stdc++.h>
using namespace std;
void maxSmaller(vector<int> arr){
    multiset<int> s;
    int maxVal = 0;
    vector<int> count(arr.size());
    for(int i = arr.size()-1; i >= 0; i--){
        s.insert(arr[i]);
        auto it = s.lower_bound(arr[i]);
        int dis = distance(s.begin(),it);
        count[i] = dis;
    }
    for(int i:count)
      cout<<i<<" ";
    cout<<endl;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
	int T; cin >> T;
	while(T--)
	    {
	        int n; cin >> n;
	        vector<int> arr(n);
	        for(int i = 0; i < n; i++)
	            cin >> arr[i];
	        maxSmaller(arr);
	    }
}
