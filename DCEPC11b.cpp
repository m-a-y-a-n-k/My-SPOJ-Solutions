#include <iostream>
using namespace std;

typedef long long LL;

/*
    Given N(natural number) and P(prime)
    Compute N! % P
    Now N<=2*1e5
        P<=2*1e5

    max(abs(P-N))=1000

    REQUIREMENTS : Wilson's Theorem and Modular Division of a number by 1 (also called Modular Inverse)
*/

void EE(LL a, LL b, LL& x, LL& y)
{
    if(a%b == 0)
    {
        x=0;
        y=1;
        return;
    }
    EE(b,a%b,x,y);
    LL temp = x;
    x = y;
    y = temp - y*(a/b);
}

LL inverse(LL a, LL m)
{
    LL x,y;
    EE(a,m,x,y);
    if(x<0) x += m;
    return x;
}

int main()
{
	// your code goes here
	ios_base::sync_with_stdio(false);
	LL T,N,P,B;
	cin>>T;
	while(T--)
	{
		cin>>N>>P;
		if(P<=N)
		{
			cout<<0<<endl;
			continue;
		}
		B=1;
		while(N++<P-1)
		{
			B=B*N;
			B=B%P;
		}
		cout<<((P-1)*((inverse(B,P))%P))%P<<endl;
	}
	// Note this code takes O(T*abs(P-N)*log(B)) time complexity..
	return 0;
}
