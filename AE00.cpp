#include <iostream>
#include <cstdio>

using namespace std;

int main()
{
    int n,x,y;
    long long ans = 0;
    scanf("%d",&n);
    for( x = 1; x <= n; x++ )
    {
        for( y = x; y <= n/x; y++ )
        {
            //cout<<x<<" * "<<y<<endl;
            ans++;
        }
    }
    printf("%lld\n",ans);
    return 0;
}
