#include <bits/stdc++.h>

using namespace std;

#define SIZE 1000001

int main()
{
	int i,j,N,size;
	
	long long ans[SIZE]={0};
	
	while(cin>>N&&N)
	{
		if(ans[N])
			;
		else
		{
			for(i=1;i<=N/2;i++)
			{
				size=min(i,N-i);
				j=1;
				while(j<=N%size)
				{
					ans[N]+=(N/i)*__gcd(i,i+j);
					j++;
				}
				while(j<=size)
				{
					ans[N]+=(N/i-1)*__gcd(i,i+j);
					j++;
				}
				
			//cout<<ans[N]<<" ";
			}
			for(i=N/2+1;i<N;i++)
			{
				j=1;
				while(j<=N-i)
				{
					ans[N]+=__gcd(i,i+j);
					j++;
				}
				
			//cout<<ans[N]<<" ";
			}
		}
		cout<<ans[N]<<endl;
	}
	return 0;
}	