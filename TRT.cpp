#include <bits/stdc++.h>

using namespace std;

int N;
int cache[2000][2000];
int treats[2000];

int profit(int left,int right)
{
    if(left>right)
        return 0;
    if(cache[left][right]!=-1)
        return cache[left][right];
    int year=N-right+left;
    return cache[left][right]=max(profit(left+1,right)+year*treats[left],profit(left,right-1)+year*treats[right]);
}

int main()
{
    cin>>N;
    for(int i=0;i<N;i++)
    {
        cin>>treats[i];
    }
    memset(cache,-1,sizeof(cache));
    cout<<profit(0,N-1)<<endl;
    return 0;
}
