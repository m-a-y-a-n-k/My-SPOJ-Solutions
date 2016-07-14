#include <cstdio>

#define MOD 1000000007
#define INV 333333336
#define ULL unsigned long long

ULL fastexpo(ULL a,ULL n)
{
    ULL ans=1;
    while(n!=0)
    {
        if((n%2)==1)
        {
            ans=ans*a;
            ans%=MOD;
        }
        a=a*a;
        a%=MOD;
        n/=2;
    }
    return ans;
}

int main()
{
    ULL n;
    while(scanf("%llu",&n)!=EOF)
    {
        if((n&1)==0)
        {
            printf("%llu\n",((fastexpo(2,n)+2)%MOD*INV)%MOD);
        }
        else
        {
            printf("%llu\n",((fastexpo(2,n)+1)%MOD*INV)%MOD);
        }
    }
    return 0;
}
