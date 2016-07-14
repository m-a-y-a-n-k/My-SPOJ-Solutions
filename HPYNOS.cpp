#include <bits/stdc++.h>

using namespace std;

int main()
{
	char no[21]={'0'};
	cin>>no;
	int l=strlen(no);
	int vals[10]={0,1,4,9,16,25,36,49,64,81};
	bool h[1000]={false},flag=false;
	long long temp=0,ans=0;
	while(1)
	{
		temp=0;
		//cout<<no<<" ";
		while(l--)
		{
			temp+=vals[no[l]-'0'];
		}
		//cout<<temp<<endl;
		if(h[temp]==true)
		{
			flag=true;
			break;
		}
		h[temp]=true;
		ans++;
		if(temp==1)
			break;
		memset(no,0,sizeof(no));
		sprintf(no,"%lld",temp);
		l=strlen(no);

	}
	if(flag==true)
		cout<<"-1";
	else
		cout<<ans;
	cout<<endl;
	return 0;
}
