#include <iostream>
#include <cstdio>
using namespace std;

char fnd(int y,long long x)
{
   if(y==0&&x==0)
    return 'R';
   long long z=x/2;
   char c=fnd(y-1,z);
   if(x!=2*z)
    (c=='R')?c='R':c='B';
   else
    (c=='R')?c='B':c='R';
   return c;
}
int main()
{
	int year;
	long long p;
	cin>>year>>p;
	(fnd(year,p)=='R')?printf("red"):printf("blue");
	return 0;
}
