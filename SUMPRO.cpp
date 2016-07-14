#include <iostream>

using namespace std;

#define MOD 1000000007

int main()
{
    ios_base::sync_with_stdio(false);
    int T,N,x;
    long long ans,a,b,n;
    cin>>T;
    while(T--)
    {
        /*
        for(x=1;x<=N;x++)
        {
            ans = ans % MOD + ( x * (N/x) ) % MOD;
            ans = ans % MOD;
        }
        cout<<ans<<endl;
        */
        cin>>N;
        ans=0;

        for(x=1;x*x<=N;x++)
        {
            ans = ( ans % MOD + ( x * (N/x) ) % MOD ) % MOD;
        }

        n = N/(--x);

        for(x=1;x<n;x++)
        {
            b=N/x;
            a=N/(x+1);
            ans = ans % MOD + ( x * ( ( b*(b+1)/2 )%MOD - ( a*(a+1)/2 )%MOD ) )%MOD;
            ans = ans % MOD;
        }

        cout<<ans<<endl;
    }
    return 0;
}
