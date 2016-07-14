#include <iostream>
#include <string>
#include <cmath>
#include <algorithm>

using namespace std;

int main()
{
    int tests,n,i;
    cin >> tests;
    string place;
    while( tests-- )
    {
        cin >> n;
        double loc[2*n],ans;
        i=0;
        while(i<n)
        {
            cin >> place >> loc[i];
            loc[n+i] = 360 + loc[i];
            i++;
        }
        sort( loc , loc + 2*n );
        ans = 99999999.0;
        for( i = 0; i < n; i++ )
        {
            ans = min( loc[n+i-1] - loc[i], ans );
        }
        ans = ans * 12;
        cout << ceil(ans) << endl;
    }
    return 0;
}
