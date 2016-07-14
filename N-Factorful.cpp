#include <bits/stdc++.h>

using namespace std;

#define MAX 1000000

typedef long long _int;

bool prime[MAX+1];
_int distinct[MAX+1],dp[8][MAX+1];

int main()
{
    _int t,n,i,x,y,j;
    cin>>t;
    for( i = 2; i <= MAX; i++ )
    {
        if( prime[i] == false )
        {
            distinct[i]++;
            for( j = 2*i; j <= MAX; j += i )
            {
                distinct[j]++;
                prime[j] = true;
            }
        }
    }
    dp[0][1] = 1;
    for( j = 0; j <= 7; j++ )
    {
        for( i = 2; i <= MAX; i++ )
        {
            if( j == distinct[i] )
                dp[j][i] = dp[j][i-1] + 1;
            else
                dp[j][i] = dp[j][i-1];
        }
    }
    while(t--)
    {
        cin>>x>>y>>n;
        if(n>=8)
            cout<<0<<endl;
        else
            cout<<dp[n][y]-dp[n][x-1]<<endl;
    }
    return 0;
}
