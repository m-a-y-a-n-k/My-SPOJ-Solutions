#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

#define MOD 10000007

int main()
{
    int i,j,n,r;
    scanf( "%d%d", &n, &r );

    if( n < r )
    {
        printf("-1\n");
        return 0;
    }

    int ans[r][n];

    memset( ans, 0, sizeof(ans) );

    for( i = 0; i < n; i++ )
    {
        ans[0][i]=1;
    }

    for( i = 1; i < r; i++ )
    {
        for( j = 1; j < n; j++ )
        {
            ans[i][j] = ( ans[i-1][j-1] + ans[i][j-1] ) % MOD;
        }
    }

    printf( "%d\n", ans[r-1][n-1] );

    return 0;
}
