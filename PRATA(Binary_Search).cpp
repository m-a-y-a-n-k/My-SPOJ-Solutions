#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    int T,P,i,L,Rank[51],low,high,mid,roti;
    cin>>T;
    while(T--)
    {
        cin>>P>>L;
        for( i=0; i<L; i++ )
        {
            cin>>Rank[i];
        }
        low = 0;
        high = 5*P*(P+1);
        while(low < high)
        {
            // cout<<"Range: "<<low<<" to "<<high<<endl;
            mid = (high + low)>>1;
            roti = 0;
            //cout<<" middle "<<mid<<endl;
            for( i=0; i<L; i++ )
            {
                roti = roti + ( sqrt( Rank[i]*Rank[i] + 8*mid*Rank[i] ) - Rank[i] )/(2*Rank[i]);
            }
            //cout<<roti<<" Rotis"<<endl;
            if( roti >= P )
            {
                //cout<<"Left"<<endl;
                high = mid;
            }
            else
            {
                //cout<<"Right"<<endl;
                low = mid + 1;
            }
        }
        cout<<low<<endl;
    }
    return 0;
}
