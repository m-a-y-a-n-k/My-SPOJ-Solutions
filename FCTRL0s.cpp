#include <iostream>
 #include <cstdio>
int main()
{
    int N,a[100000],x,index,c,n,temp=0,digit;
    char ch='Y';
    while(1)
    {
    	scanf("%d",&N);
    	a[0]=1;
    	digit=1;
    	for(n=1;n<=N;n++)
    	{
    		for(index=0;index<digit;index++)
    		{
    			x=n*a[index]+temp;
    			a[index]=x%10;
    			temp=x/10;
    		}
    		while(temp)
    		{
    			a[index]=temp%10;
    			temp=temp/10;
    			index++;
    			digit++;
    		}
    	}
    	c=0;
		index=0;
        while(index<digit)
        {
        	if(a[index]==0)
        	 c++;
        	else
			 break;
        	index++;
        }
        printf("%d\nContinue??\n",c);
        ch=getchar();
        if(ch=='N')
         break;
    }
    return 0;
}
