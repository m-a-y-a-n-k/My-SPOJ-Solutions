#include <iostream>
using namespace std;

int main() {
	double a,b,c;
	while(1)
	{
	  cin>>a>>b>>c;
	  if(b==0&&a==0&&c==0)
	   break;
	  else if(b/a==c/b)
	   cout<<"GP "<<(int)(c*(int)(b/a))<<endl;
	  else if((int)(c-b)==(int)(b-a))
	   cout<<"AP "<<(int)(c+b-a)<<endl;
	}
	return 0;
}