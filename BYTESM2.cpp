#include <bits/stdc++.h>

using namespace std;

int B[101][101],h,w;
long long memo[101][101],ans;

long long compute(int i,int j)
{
	if(j==-1||j==w||i==h)
		return 0;
	if(memo[i][j])
		return memo[i][j];
	return memo[i][j]=B[i][j]+max(compute(i+1,j-1),max(compute(i+1,j),compute(i+1,j+1)));
}

int main()
{
    int T,i,j;
    cin>>T;
    while(T--)
    {
        cin>>h>>w;
        memset(B,0,sizeof(B));
        for(i=0;i<h;i++)
            for(j=0;j<w;j++)
                cin>>B[i][j];
        memset(memo,0,sizeof(memo));
        for(j=0;j<w;j++)
            compute(0,j);
        ans=0;
		for(j=0;j<w;j++)
			ans=max(ans,memo[0][j]);
		cout<<ans<<endl;
	}
	return 0;
}
