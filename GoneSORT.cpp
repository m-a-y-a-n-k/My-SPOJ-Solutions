#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    int T,B,i,j,*data,*SORT,Count,Max;
    cin>>T;
    while(T--)
    {
        cin>>B;
        data = new int[B];
        SORT = new int[B];
        for( i = 0; i<B; i++ )
        {
            cin>>data[i];
            SORT[i] = data[i];
        }
        sort(SORT,SORT+B);
        Max = 0;
        for( i = 0; i<B; )
        {
            Count = 0;
            for( j = 0; j<B ; j++ )
            {
                if( data[j] == SORT[i] )
                {
                    Count++;
                    i++;
                }
            }
            if( Count > Max )
                Max = Count;
        }
        cout<<B-Max<<endl;
    }
    return 0;
}
