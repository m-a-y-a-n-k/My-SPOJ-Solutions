#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

int main()
{
	int T,key,k,i,len;
	char S[100001];
	scanf("%d",&T);
	while(T--)
	{
	  scanf("%d",&key);
	  scanf("%s",S);
	  i=-1,len=strlen(S);
	  while(++i<len)
	  {
	   if(S[i]>='a')
	   {
	    if((S[i]+key)<='z')
	     S[i]+=key;
	    else
	    {
	    	k=key%26;
	     if(key<26)
	      S[i]=S[i]+key-26;
	     else if((S[i]+k)<='z')
	         S[i]=S[i]+k-32;
	     else
	      S[i]=S[i]+k-26-32;
	    }
	   }
	   else if(S[i]>='A')
	   {
	    if((S[i]+key)<='Z')
	     S[i]+=key;
	    else
	    {
	    	k=key%26;
	     if(key<26)
	      S[i]=S[i]+key-26;
	     else if((S[i]+k)<='Z')
	         S[i]=S[i]+k+32;
	     else
	      S[i]=S[i]+k-26+32;
	    }
	   }
	   else
	    S[i]=' ';
	  }
	  puts(S);
	  cout<<endl;
	}
	return 0;
}
