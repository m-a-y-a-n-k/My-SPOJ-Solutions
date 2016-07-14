#include <cstdio>
#include <cstring>

int ans[101],sum[101],N;

int solve( int day )
{
    int i,j,work,x;
    if( day > N )
        return 0;
    // if we already found the max work till day
    if( ans[day] != -1 )
        return ans[day];

    // we will add the best answer for 'day' + 1 to N to 'day' and add it to work done till ith day to jth day
    work = 0;
    for( i = day; i <= N; i++ )
    {
        for( j = i; j <= N && sum[j] + sum[day-1] < 2 * sum[i] ; j++ )
        {
            x = sum[j] - sum[i] + solve(j+1);
            if( work < x )
                work = x;
        }
    }
    return ans[day] = work;
}

int main()
{
    int T, work , i, x;
    scanf( "%d", &T );
    while( T-- )
    {
        scanf( "%d" , &N );
        for ( i = 1; i <= N; i++ )
        {
            scanf( "%d" , &x );
            sum[i] = sum[i-1] + x;
        }
        memset( ans , -1, sizeof( ans ) );
        work = solve(1);
        // This value will be subtracted from total work till ' N ' days to give us the answer for boss "LINGATES".
        printf( "%d %d\n", sum[N] - work, work );
    }
    return 0;
}
