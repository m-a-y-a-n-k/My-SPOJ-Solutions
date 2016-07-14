#include <bits/stdc++.h>

using namespace std;

#define SIZE 1000001

int phi[SIZE]={0};

int main()
{
	int i,j,N;
	long long ans[SIZE]={0};
	
	phi[1]=1;
	
	//used the lemma that if x = (p1^k1)*(p2^k2)*(p3^k3) ... phi[x]=(p1-1)^k1*(p2-1)^k2*(p3-1)^k3
	
	//used the property that phi[a*b]=phi[a]*phi[b] if gcd(a,b)=1
	
	for(i=2;i<SIZE;i++)
	{
		if(phi[i]==0)
		{
			phi[i]=i-1;					//because the primes will be left-out...
			for(j=2;i*j<SIZE;j++)
			{
				if(phi[j]!=0)
				{
					int q=j;		
					int f=i-1;
					// If i is not prime relative to j loop is performed to find an equivalent 
					// q is j by highest power factor of i and f is compensating 
					while(q%i==0)
					{
						f*=i;
						q/=i;
					}
					//in order to exploit the property of multiplication....
					phi[i*j]=f*phi[q];
				}
			}
		}
	}
	
	for(i=1;i<SIZE;i++)
	{
		for(j=2;j*i<SIZE;j++)
			ans[i*j]+=i*phi[j];
		ans[i]+=ans[i-1];
	}
	
	while(scanf("%d",&N)==1&&N)
	{
		printf("%lld\n",ans[N]);
	}
	return 0;
}	