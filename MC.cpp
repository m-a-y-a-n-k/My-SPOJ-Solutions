#include <iostream>
#include <cstring>
#include <string>

using namespace std;

string one,two;

int main()
{
    int i,j,m,n;
    long long res;
    while( 1 )
    {
        getline( cin, one );
        if( one[0] == '#' || !getline( cin, two ) )
            break;
        one = "$" + one;
        two = "$" + two;
        n = one.size();
        m = two.size();
        int csl[n][m];
        memset( csl, 0, sizeof(csl) );
        for( i = 1; i < n; i++ )
        {
            for( j = 1; j < m; j++ )
            {
                if( one[i] == two[j] )
                {
                    csl[i][j] = csl[i-1][j-1] + 1;
                }
                else
                {
                    csl[i][j] = max( csl[i-1][j-1], max( csl[i][j-1], csl[i-1][j] ) );
                }
            }
        }
        res = csl[--n][--m];
        res = 30*( m - res ) + 15*( n - res );
        cout << res << endl;
    }
    return 0;
}

