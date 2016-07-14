#include <bits/stdc++.h>
#include <cstdio>

using namespace std;

int main()
{
    int n = 0, x, root, N,succ,pred;
    scanf("%d",&N);
    long long ans = 0;
    map <int,long long> Srt;
    while( n++ < N )
    {
        scanf("%d",&x);                               // x is an element
        Srt[x] = 0;                             // height of x is set to minimum

        if( n == 1 )
        {
            root = x;
            printf("0\n");
            continue;
        }

        map <int,long long> :: iterator loc_x = Srt.find(x);
        map <int,long long> :: iterator loc_ors = loc_x;

        succ = pred = 0;

        if( root < x )            // leftmost in sorted order
        {
            if( ++loc_ors != Srt.end() )
                succ = loc_ors->second;
            pred = (--loc_x)->second;
        }
        else
        {
            succ = (++loc_ors)->second;
            if( loc_x != Srt.begin() )
                pred = (--loc_x)->second;
        }
        Srt[x] = max( succ, pred ) + 1;
        ans = ans + Srt[x];
        printf("%lld\n",ans);
    }
    return 0;
}
