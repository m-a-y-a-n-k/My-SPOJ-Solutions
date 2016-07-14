#include <iostream>
#include <vector>
#include <cstdio>
#include <cstring>

using namespace std;

int main()
{
    string one,two;
    vector <char> SCS;
    int i,j,l1,l2,k;
    while ( cin >> one )
    {
        cin >> two;
        one = "$" + one;
        two = "$" + two;
        l1 = one.size();
        l2 = two.size();
        // Shortest Common Super-Sequence.
        int scs[l1][l2];
        for( i = 0; i < l1; i++ )
            scs[i][0] = i;
        for( j = 0; j < l2; j++ )
            scs[0][j] = j;
        for( i = 1; i < l1; i++ )
        {
            for( j = 1; j < l2; j++ )
            {
                if( one[i] == two[j] )
                {
                    scs[i][j] = 1 + scs[i-1][j-1];
                }
                else
                {
                    scs[i][j] = 1 + min( scs[i][j-1], scs[i-1][j] );
                }
            }
        }
        i = l1 - 1;
        j = l2 - 1;
        while( i > 0 && j > 0 )
        {
            if( one[i] == two[j] )
            {
                SCS.push_back( one[i] );
                i--;
                j--;
            }
            else
            {
                if( scs[i][j-1] >= scs[i-1][j] )
                {
                    SCS.push_back( one[i--] );
                }
                else
                {
                    SCS.push_back( two[j--] );
                }
            }
        }
        if( i == 0 )
        {
            while( j > 0)
                SCS.push_back( two[j--] );
        }
        else if( j == 0 )
        {
            while( i > 0 )
                SCS.push_back( one[i--] );
        }
        l1 = SCS.size();
        for(i = 0 ; i < l1 ; i++ )
            cout << SCS[l1-i-1] ;
        cout << endl;
        SCS.clear();
    }
    return 0;
}
