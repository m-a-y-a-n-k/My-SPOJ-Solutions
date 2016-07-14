#include <iostream>
#include <cmath>

using namespace std;

int tests,t,N,i,n,x,ones[33];
long long ans;
const int MOD = 10000007;

int main()
{
    ios_base::sync_with_stdio(false);
    cin >> tests;
    t = tests;
    while(tests--)
    {
        cin >> N;
        for( i = 0; i <= 32; i++ )
        {
            ones[i] = 0;
        }
        for( n = 0; n < N; n++ )
        {
            cin >> x;
            for( i = 0; i < 32; i++ )
            {
                if( ( x & ( 1 << i ) ) != 0 )
                {
                    ones[ i ]++;
                }
            }
        }
        ans = 0;
        for( i = 0; i < 32; i++ )
        {
            ans = ( ans + ( N - ones[i] ) * ones[i] ) % MOD ;
        }
        ans = ( 2 * ans )%MOD;
        cout << "Case " << t - tests << ": " << ans << endl;
    }
    return 0;
}
