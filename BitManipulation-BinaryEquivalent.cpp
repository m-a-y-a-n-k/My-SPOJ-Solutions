#include<iostream>
#include<string>
#include<cmath>
using namespace std;

int main()
{
	long long n;
	string S="";
	cin>>n;
	for(int i=63;i>=0;i--)
	 S+=(n&1<<i)?"1":"0";
	cout<<"BINARY EQUIVALENT:\n"<<S<<endl;
	n=0;
	for(int i=0;i<64;i++)
	{
		if(S[i]=='1')
		 S[i]='0';
		else
		 S[i]='1';
		n+=(S[i]-48)*pow(2,i);
	}
	cout<<"One\'s Compliment:\n"<<S<<endl;
	cout<<"Decimal Value:\n"<<n<<endl;
	return 0;
}
