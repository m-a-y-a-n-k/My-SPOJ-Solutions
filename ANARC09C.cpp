#include <bits/stdc++.h>

using namespace std;

bool prime[1000001]={false};

int main()
{
    ios_base::sync_with_stdio(false);
    long long i,j,k=0,A,B,X,D,powA,powB;
    bool flag;
    prime[1]=true;
    for(i=2;i*i<=1000000;i++)
    {
        if(prime[i]==false)
        {
            for(j=i*i;j<=1000000;j+=i)
                prime[j]=true;
        }
    }
    while(1)
    {
        cin>>A>>B;
        if(A==0&&B==0)
            break;
        k++;
        X=D=0;
        if(A<B)
        {
            A=A+B;
            B=A-B;
            A=A-B;
        }
        for(i=1;i<=A;i++)
        {
            powA=powB=0;
            flag=false;
            if(A%i==0)
            {
                if(!prime[i])
                {
                    j=i;
                    flag=true;
                    X++;
                    while(A%j==0)
                    {
                        j*=i;
                        powA++;
                    }
                }
            }
            if(B%i==0)
            {
                if(!prime[i])
                {
                    j=i;
                    if(flag==false)
                        X++;
                    while(B%j==0)
                    {
                        j*=i;
                        powB++;
                    }
                }
            }
            if(powA<powB)
            {
                powA=powA+powB;
                powB=powA-powB;
                powA=powA-powB;
            }
            D+=(powA-powB);
        }
        cout<<k<<". "<<X<<":"<<D<<endl;
    }
    return 0;
}
