#include <iostream>
#include <cstring>

using namespace std;

#define MOD 1000000007

typedef long long _int;

_int A[2001],B[2001],memo[2001][2001];

void solve( _int idx, _int sum )
{
    if( memo[idx][sum] != 0 || idx == 0 )
        return ;
    _int j;
    for( j = A[idx]; j<=sum && j<=B[idx]; j++ )
    {
        solve( idx-1, sum-j );
        //cout<<"("<<idx-1<<","<<sum-j<<") ";
        memo[idx][sum] = ( memo[idx][sum] + memo[idx-1][sum-j] )%MOD;
    }
    //cout<<endl;
}

int main()
{
    _int n,sum,idx,T,j;
    cin>>T;
    while(T--)
    {
        cin>>n>>sum;
        for( idx = 1; idx <= n; idx++ )
        {
            cin>>A[idx]>>B[idx];
        }
        memset( memo, 0, sizeof(memo) );
        memo[0][0] = 1;
        solve( n, sum );
        cout<<memo[n][sum]%MOD<<endl;
    }
    while(cin>>n)
        ;
    return 0;
}
