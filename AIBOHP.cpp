#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

int LCS[6101][6101];

int main()
{
    int t,T,i,j,s;
    string one,two;
    scanf("%d",&T);
    for( t=1; t<=T; t++ )
    {
        cin>>one;
        two = one;
        reverse( two.begin(), two.end() );
        s = one.size() + 1;
        one = "#" + one;
        two = "#" + two;
        for( i = 0; i < s; i++ )
        {
            for( j = 0; j < s; j++ )
            {
                if( i == 0 || j == 0 )
                {
                    LCS[i][j] = 1;
                    continue;
                }
                if( one[i] == two[j] )
                {
                    LCS[i][j] = LCS[i-1][j-1] + 1;
                }
                else
                {
                    LCS[i][j] = max( max( LCS[i-1][j-1] , LCS[i][j-1] ), LCS[i-1][j] );
                }
                //cout<<LCS[i][j]<<" ";
            }
           // cout<<endl;
        }
        cout<<s-LCS[s-1][s-1]<<endl;
    }
    return 0;
}
