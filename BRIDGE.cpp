#include <iostream>
#include <utility>
#include <algorithm>
#include <cstdio>

int start[1002],end[1002],lis[1002],i,j,T,N,ans;

using namespace std;
pair <int,int> edges[1002];

// Find the maximum number of rods such that they don't intersect.
// Task is to remove minimum number of rods such that all rods un-removed are non - intersecting (at point other than end point)

void LIS()
{
    sort( edges, edges + N );
    ans = 0;
    for( i = 0; i < N; i++ )
    {
        lis[i] = 1;
        for( j = i-1; j >= 0; j-- )
        {
            if( edges[i].second >= edges[j].second )
            {
                lis[i] = max( lis[i], lis[j] + 1 );
            }
        }
        ans = max( lis[i], ans);
    }
    printf( "%d\n", ans );
}

int main()
{
    scanf( "%d", &T );
    while( T-- )
    {
        scanf( "%d" , &N );
        for ( i = 0; i < N; i++ )
        {
            scanf( "%d" , &start[i]);
        }
        for ( i = 0; i < N; i++ )
        {
            scanf( "%d" , &end[i]);
        }
        for( i = 0; i < N; i++ )
        {
            edges[i] = make_pair(start[i],end[i]);
        }
        LIS();
    }
    return 0;
}
