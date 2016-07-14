#include<bits/stdc++.h>
using namespace std;

#define ll	long long

// Find Sum in O(n).. Use the remainder.. and find the day in <= O(n)

int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n;
		scanf("%d",&n);
		ll arr[n],sum=0;
		for(int i=0;i<n;++i)
		{
			scanf("%lld",&arr[i]);
			sum+=arr[i];
		}
		ll m;
		scanf("%lld",&m);
		m%=sum;
		int day;
		if(m==0)
		{
			for(int i=n-1;i>=0;--i)
			{
				if(arr[i]!=0)                   // If elements are consecutive 0s at end
				{
					day=i+1;
					break;
				}
			}
		}
		else
		{
			for(int i=0;i<n;++i)
			{
				m-=arr[i];                    //Distance left till milestone
				if(m<=0)       // If milestone reached(also accounts if advances further )
				{
					day=i+1;
					break;
				}
			}
		}
		printf("DAY %d\n",day);
	}
	return 0;
}
