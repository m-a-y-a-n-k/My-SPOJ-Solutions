#include <iostream>

using namespace std;

#define MOD 1000000007

unsigned long long base[2][2];
unsigned long long temp[2][2];

void expo(int n)                    // Implements a matrix for n th fibonacci number (at the off diagonal) by exponentiation
{
    if(n<=1)
        return;

    expo(n/2);

    temp[0][0]=(base[0][0]*base[0][0]%MOD+base[0][1]*base[1][0]%MOD)%MOD;
    temp[0][1]=(base[0][0]*base[0][1]%MOD+base[0][1]*base[1][1]%MOD)%MOD;
    temp[1][0]=(base[1][0]*base[0][0]%MOD+base[1][1]*base[1][0]%MOD)%MOD;
    temp[1][1]=(base[1][0]*base[0][1]%MOD+base[1][1]*base[1][1]%MOD)%MOD;
    base[0][0]=temp[0][0];
    base[0][1]=temp[0][1];
    base[1][0]=temp[1][0];
    base[1][1]=temp[1][1];

    if(n%2==1)
    {
        base[0][0]=base[0][1]+base[0][0];
        base[0][1]=MOD+base[0][0]-base[0][1];
        base[1][0]=base[1][1]+base[1][0];
        base[1][1]=MOD+base[1][0]-base[1][1];
        base[0][0]%=MOD;
        base[0][1]%=MOD;
        base[1][0]%=MOD;
        base[1][1]%=MOD;
    }
    /*
    cout<<endl;
    cout<<"Power"<<n<<endl;
    cout<<base[0][0]<<" "<<base[0][1]<<endl;
    cout<<base[1][0]<<" "<<base[1][1]<<endl;
    */
}

int main()
{
    unsigned int T,N,M;
    long long a,b;
    cin>>T;
    while(T--)
    {
        cin>>N>>M;
        base[0][0]=base[0][1]=base[1][0]=1;base[1][1]=0;
        temp[0][0]=temp[0][1]=temp[1][0]=temp[1][1]=0;
        expo(M+1);
        a=base[0][0];
        base[0][0]=base[0][1]=base[1][0]=1;base[1][1]=0;
        temp[0][0]=temp[0][1]=temp[1][0]=temp[1][1]=0;
        expo(N);
        b=base[0][0];
        cout<<(MOD+a-b)%MOD<<endl;
    }
    return 0;
}
