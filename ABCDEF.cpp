#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

vector <int> data;
vector <int> lhs;
vector <int> rhs;

int main()
{
    int n,i,j,k;
    long long ans=0;
    scanf("%d",&n);
    for( i=0; i<n; i++ )
    {
        cin>>k;
        data.push_back(k);
    }
    for( i=0; i<n; i++ )
    {
        for( j=0; j<n; j++)
        {
            for( k=0; k<n; k++ )
            {
                lhs.push_back( data[i] * data[j] + data[k] );
            }
        }
    }

    for( i=0; i<n; i++ )
    {
        if(data[i]!=0)
        {
            for( j=0; j<n; j++ )
            {
                for( k=0; k<n; k++ )
                {
                    rhs.push_back( data[i] * ( data[j] + data[k] ) );
                }
            }
        }
    }

    sort( lhs.begin(), lhs.end() );
    sort( rhs.begin(), rhs.end() );
 /*   cout<<"LHS\tRHS"<<endl;

    for( i=0; i<n*n*n; i++ )
    {
        cout<<lhs[i]<<"\t"<<rhs[i]<<endl;
    }
*/
    for( i=0; i<n*n*n; i++ )
    {
        ans = ans + upper_bound(rhs.begin(),rhs.end(),lhs[i])-lower_bound(rhs.begin(),rhs.end(),lhs[i]);
    }

    cout<<ans<<endl;

    return 0;
}
