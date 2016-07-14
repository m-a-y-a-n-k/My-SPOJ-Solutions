#include <bits/stdc++.h>

using namespace std;

#define MAX 1000000000

int val[10001][3];

int main() {
	// your code goes here
	int T,n,i,j,ans;
	cin>>T;
	while(T--)
	{
		cin>>n;
		memset(val,0,sizeof(val));
		for(i=0;i<n;i++)
			for(j=0;j<3;j++)
				{cin>>val[i][j];}
		ans=MAX;
		for(i=1;i<n;i++)
		{
			ans=MAX;
			for(j=0;j<3;j++)
			{
				val[i][j]+=min(val[i-1][(j+1)%3],val[i-1][(j+2)%3]);
				ans=min(ans,val[i][j]);
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}