#include <iostream>
#include <cstdio>

using namespace std;

int search(float c,float *dp)
{
  int beg=1,end=275,mid=-1;
  while(beg<=end)
  {
    mid=beg+(end-beg)>>1;
    if((dp[mid]<c&&dp[mid+1]>=c)||mid==end)
     return (mid==1)?1:mid+1;
    else if(dp[mid]>=c)
     end=(end>mid)?mid-1:mid;
    else
     beg=(beg<mid)?mid+1:mid;
  }
  return mid;
}
int main()
{
    float dp[276];
    dp[1]=0.5;
    for(int i=2;i<=275;i++)
    {
     dp[i]=dp[i-1]+1.0/((float)i+1.0);
    }
    float c;
    do
    {
     scanf("%f",&c);
     if(c)
     printf("%d card(s)\n",search(c,dp));
    }while(c);
	return 0;
}
