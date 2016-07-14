#include <iostream>
#include <string>
#include <cmath>
#include <cstdio>
using namespace std;

int main()
{
	int T,a,b,c,x,y;
	string S;
	cin>>T;
	while(T--)
	{
		a=b=c=0;
		printf("\n");
		cin>>S;
		y=x=S.size();
		if(S.find("machula")==-1)
		 while(x--)
		  a+=(S.at(x)-'0')*pow(10,y-x-1);
		getchar();
		getchar();
		cin>>S;
		y=x=S.size();
		if(S.find("machula")==-1)
		 while(x--)
		  b+=(S.at(x)-'0')*pow(10,y-x-1);
		getchar();
		getchar();
		cin>>S;
		y=x=S.size();
		if(S.find("machula")==-1)
		 while(x--)
		  c+=(S.at(x)-'0')*pow(10,y-x-1);
		if(!a)
		 cout<<c-b<<" + "<<b<<" = "<<c<<endl;
		else if(!b)
		 cout<<a<<" + "<<c-a<<" = "<<c<<endl;
		else if(!c)
		 cout<<a<<" + "<<b<<" = "<<a+b<<endl;
		else
		 cout<<a<<" + "<<b<<" = "<<c<<endl;
	}
	return 0;
}
