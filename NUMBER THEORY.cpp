#include <stdio.h>
#include <iostream>
#define MQ 1000000007

using namespace std;

/*
PROLOGUE : THIS CODE IS ABOUT EUCLID's GCD theorem , MODULAR EXPONENTIATION, And MODULAR MULTIPLICATION
*/
int GCD(int A, int B)      // EUCLID's GCD is based on observation that gcd(a,b) = gcd(b,remainder) where b < a
{
    if(B==0)
        return A;
    else
        return GCD(B, A % B);
}
int x,y;
void extendedGCD(int a,int b)           // Finding coefficients of linear equation ax+by=gcd(a,b)
{
	if(b==0)
	{
		x=1;
		y=0;
		cout<<"GCD"<<a<<endl;
	}
	else
	{
		extendedGCD(b,(a%b));
		int t=x;
		x=y;
		y=t-(a/b)*y;
	}
}

int main()
{
    int N,i;
    scanf("%d",&N);
    long long A[N],f=1,g,ans;
    for(i=0;i<N;i++)
    {
    	scanf("%lld",&A[i]);
    	f=(f%MQ*A[i]%MQ)%MQ;                 //MODULAR MULTIPLICATION --> (a*b)%M = (a%M * B%M)%M.
    }
    g=GCD(A[0],A[1]);
    for(i=1;i<N-1;i++)
     g=GCD(g,A[i+1]);
    ans=1;
    while(g!=0 )              // MODULAR EXPONENTIATION , exponent is converted to binary form .. and number is multiplied itself .Answer is computed in just log(N) i.e binary length times
    {
           if(g%2 == 1)
           {
             ans = ans*f ;
             ans = ans%MQ;
           }
           f = f*f;
           f%= MQ;
           g /= 2;
    }
    printf("%lld",ans);
    return 0;
}

