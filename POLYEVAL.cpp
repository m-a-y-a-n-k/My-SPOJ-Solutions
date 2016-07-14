#include <iostream>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    int n,k,x,i,*coeff,c=1;
    long long result;
    while(1)
    {
        cin>>n;
        if(n==-1)
            break;
        cout<<"Case "<<c++<<":"<<endl;
        coeff = new int[n+1];
        for(k=0;k<=n;k++)
            cin>>coeff[k];
        cin>>k;
        for(;k--;)
        {
            cin>>x;
            result = 0;
            for(int i=0;i<=n;i++)
            {
                result = result * x + coeff[i];
            }
            cout<<result<<endl;
        }
    }
    return 0;
}
