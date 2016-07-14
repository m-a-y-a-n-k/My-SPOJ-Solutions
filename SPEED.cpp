#include <bits/stdc++.h>

using namespace std;

// answer is L.C.M of two until both meet at 

int main() 
{
	long long t;
	scanf("%lld",&t);
	while(t--)
	{
	  long long a,b;
	  scanf("%lld%lld",&a,&b);
	  long long ans=abs(a-b);
	  if(a<0)a=-a;
	  if(b<0) b=-b;
	  ans=ans/__gcd(a,b);
	  printf("%lld\n",ans);
	}
	return 0;
}