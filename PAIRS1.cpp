#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    int N,K,i,n;
    cin>>N>>K;
    vector <int> V;
    for( i=0; i<N; i++ )
    {
        cin>>n;
        V.push_back(n);
    }
    sort( V.begin(), V.end() );
    long long Cnt = 0;
    for( i=0; i<N; i++ )
    {
        if(binary_search(V.begin(),V.end(),V[i]+K)==true)
            Cnt++;
    }
    cout<<Cnt<<endl;
    return 0;
}
