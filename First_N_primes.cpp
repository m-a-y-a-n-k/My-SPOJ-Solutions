#include<iostream>
#include<cstdio>
int main()
{
    int T,N;
    scanf("%d",&T);
    while(T--)
    {
    	scanf("%d",&N);
    	printf("2 3 ");
    	for(int i=5;N>2;i++)
   		{
   			int flag;
   			if(i%2==0||i%3==0)
   			 flag=0;
   			else
   			 flag=1;
   			for(int j=5;j*j<i;j+=6)
    		  if(i%j==0||i%(j+2)==0)
    		    { flag=0;break;}
    		if(flag)
    		{
    			printf("%d ",i);
    		    N--;
    		}
   		}
   		printf("\n");
    }
    return 0;
}

