#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    int S,i,j,ans;
    cin>>S;
    int army1[S],army2[S];
    for(i=0;i<S;i++)
    {
        cin>>ans;
        army1[i]=ans;
    }
    for(i=0;i<S;i++)
    {
        cin>>ans;
        army2[i]=ans;
    }
    sort(army1,army1+S);
    sort(army2,army2+S);
    ans=0;
    for(i=0,j=0;i<S&&j<S;)
    {
        if(army1[i]<army2[j])
        {
            ans++;
            i++;
            j++;
        }
        else if(army1[i]==army2[j])
        {
            j++;
        }
        else
            j++;
    }
    cout<<ans<<endl;
    return 0;
}
