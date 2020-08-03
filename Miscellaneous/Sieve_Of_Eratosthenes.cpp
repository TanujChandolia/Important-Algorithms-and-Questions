#include <iostream>
#include <vector>
using namespace std;

//CALCULATES PRIME NUMBERS IN O(n log log n) TIME.
int main()
{
  int n;
  cin >> n;
  vector <char> v(n+1 , true);
  v[0] = v[1] = false;

  for(int i = 2; i <= n; i++)
  {
    if(v[i] && (long long)i*i <=n)
    {
      for(int j = i*i; j <= n; j += i)
      {
          v[j] = false;
      }
    }
  }

  for(int i = 0; i < v.size(); i ++)
  {
    if(v[i] == true && ((long long)i*i <= n))
      cout<<i<<" ";
  }
  return 0;
}
