#include <iostream>
#include <cstring>

using namespace std;

#define LIMIT 1000001

long long BIT[LIMIT];

int main()
{
    int T,N,val,i,idx;
    long long result;
    cin>>T;
    while(T--)
    {
        cin>>N;
        result = 0;
        memset(BIT,0,sizeof(BIT));
        for( i=0; i<N; i++ )
        {
            cin>>val;
            idx = val;
            if(idx == 0)
            {
                continue;
            }
            while( idx < LIMIT )
            {
                BIT[idx] += val;
                idx = idx + (idx & -idx);
            }
            idx = val-1;
            while( idx > 0 )
            {
                result += BIT[idx];
                idx = idx - (idx & -idx);
            }
        }
        cout<<result<<endl;
    }
    return 0;
}
