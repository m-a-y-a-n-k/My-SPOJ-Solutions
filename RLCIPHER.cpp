#include <iostream>
#include <cstdio>
using namespace std;

bool check(int x)
{
 if(x>=0)
  if(x%3==0||x%4==0||(x-3)%4==0||(x-4)%3==0)
   return true;
 return false;
}

int main()
{
	int x,t,n;
	scanf("%d",&t);
	while(t--)
	{
     	scanf("%d",&n);
    	while(n--)
     	{
          scanf("%d",&x);
    	  if(x==2||x==1||x==0)
    	  {
     	    cout<<x-4<<" ";
    	    continue;
    	  }
    	  if(check(x))
    	  {
    	    cout<<"-4 ";
    	  }
    	  else if(check(x-7))
    	   cout<<"-4 ";
    	  else if(check(x-6))
    	   cout<<"-4 ";
    	  else if(x>=0)
    	   cout<<x%4-4<<" ";
    	  else
    	   cout<<x<<" ";
    	}
	    cout<<endl;
	}
	return 0;
}
