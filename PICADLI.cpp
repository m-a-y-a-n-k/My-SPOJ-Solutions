#include <iostream>
#include <utility>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int Min,Max,N,i,lo,hi,Sum;
    while( cin >> Min && cin >> Max && cin >> N )
    {
        Min *= 2;
        Max *= 2;
        vector < pair < int, int > > instant;
        instant.push_back(make_pair(Min,0));
        instant.push_back(make_pair(Max,0));
        i = 0;
        while( i++ < N )
        {
            cin >> lo >> hi;
            instant.push_back(make_pair(2*lo-1,1));
            instant.push_back(make_pair(2*hi+1,-1));
        }
        sort( instant.begin(), instant.end() );
        lo = Min;
        hi = Max;
        Sum = Max = 0;
        Min = N;
        N = instant.size();
        for( i = 0; i < N; i++ )
        {
            if( lo <= instant[i].first && instant[i].first <= hi )
            {
                Max = max(Max,Sum);
                Min = min(Min,Sum);
            }
            Sum += instant[i].second;
        }
        cout << Min << " " << Max << endl;
    }
    return 0;
}
