#include <iostream>
#include <string>

using namespace std;

#define MAX 101

int result[MAX][MAX][MAX],l2,l1,i,j,k,K,ans,tests;

string one,two;

void solve(int i,int j,int k)
{
    if( k == 0 )                // ashirvad complete
    {
        result[i][j][k] = 0;
        return ;
    }
    if( i == 0 || j == 0 )
    {
        result[i][j][k] = -1;           // ashirvad not possible
        return ;
    }
    if( result[i][j][k] != -2 )         // ashirvad has been already computed
        return ;
    if( one[i] == two[j] )
    {
        solve(i-1,j-1,k-1);                         // solve this first
        if( result[i-1][j-1][k-1] == -1 )
            result[i][j][k] = -1;                   // no ashirvad possible
        else
            result[i][j][k] = max( result[i][j][k], result[i-1][j-1][k-1] + one[i]);            // best ashirvaad
    }
    // solve remaining cases first.
    solve(i-1,j,k);
    solve(i,j-1,k);
    // solve( i-1,j-1,k) will be automatically called after one lvl of recursion
    result[i][j][k] = max( result[i][j][k] , max( result[i][j-1][k], result[i-1][j][k] ) );
    return ;
}

int main()
{
    cin >> tests;
    while( tests-- )
    {
        cin >> one >> two >> K;
        one = "$" + one;
        two = "$" + two;
        l1 = one.size();
        l2 = two.size();
        for( i = 0; i < l1; i++ )
        {
            for( j = 0; j < l2; j++ )
            {
                for( k = 0; k <= K; k++ )
                    result[i][j][k] = -2;
            }
        }
        solve(l1-1,l2-1,K);
        ans = result[l1-1][l2-1][K];
        if( ans == -1 )                         // if no ashirvad possible
            ans++;
        cout << ans << endl;
    }
    return 0;
}
