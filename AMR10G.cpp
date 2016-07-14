#include <iostream>
#include <algorithm>
#include <cstdio>

using namespace std;

long long data[200001];

int main()
{
    int T,k,n,N,ans,m;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d%d",&N,&k);
        for( n=0; n<N; n++ )
            scanf("%d",&data[n]);
        if( k == 1 )
        {
            cout<<0<<endl;
            continue;
        }
        sort( &data[0], &data[0] + N );
        m = data[k-1] - data[0];
        for( n=1; n + k <= N; n++ )
        {
            ans = data[k-1+n] - data[n];
            if( ans < m )
                m = ans;
        }
        printf("%d\n",m);
    }
    return 0;
}
