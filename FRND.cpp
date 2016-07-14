#include <cstdio>

int main()
{
    int N,K,i=0,j,val;
    long long bin[23]={0};
    long long sum;
    scanf("%d",&N);
    sum=0;
    for(i=0;i<N;i++)
    {
        scanf("%d",&val);
        sum=val;
        for(j=0;j<23;j++)
        {
            if((val>>j)&1)               // number of bits enabled at j position
                bin[j]++;
        }
    }
    if(N!=1)
        sum=0;
    for(i=0;i<23;i++)
    {
        sum+=(bin[i]*(N-bin[i])*(1<<i));                // contribution of binary j ...
    }
    printf("%lld\n",sum);
    return 0;
}
