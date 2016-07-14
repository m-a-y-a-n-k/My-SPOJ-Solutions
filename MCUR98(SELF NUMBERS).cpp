#include <iostream>
#include <cstring>

using namespace std;

#define SIZE 1000000
bool visit[SIZE];

int main()
{
    ios_base::sync_with_stdio(false);
    memset(visit,false,sizeof(visit));
    int i,sum,x;
    for( i=1; i<SIZE; i++ )
    {
        x = sum = i;
        while( x > 0 )
        {
            sum = sum + x%10;
            x = x/10;
        }
        visit[sum]=true;
    }
    for( i=1; i<SIZE ;i++ )
    {
        if( visit[i] == false )
            cout<<i<<endl;
    }
    return 0;
}
