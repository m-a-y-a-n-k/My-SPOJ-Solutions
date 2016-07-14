#include <iostream>
#include <vector>
#include <cstdio>

using namespace std;

vector <int> lucky;
vector <int> values;
int i,inc,n;
vector <int> :: iterator loc;

int main()
{
    ios_base::sync_with_stdio(false);

    for( i = 2; i <= 63000; i++ )
    {
        values.push_back(i);
    }
    while( values.size() != 0 )
    {
        loc = values.begin();
        inc = *loc - 1;
        loc = loc + inc;
        values.erase(values.begin());
        lucky.push_back(inc+1);
        while( loc - values.begin() + inc <= values.size() )
        {
            values.erase(loc);
            loc += inc;
        }
    }

    while( scanf("%d",&n) && n > 0 )
    {
        printf( "%d\n" , lucky[n-1] );
    }
    return 0;
}
