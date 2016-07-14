/*
 SEGMENTED SIEVE OF ERATOSTHENES WORKS FOR A RANGE or SEGMENT
Say i need to find the prime numbers between 125 and 140 .
One way is to find all primes till 140 using traditional sieves and then find how many of them are greater than 125.
This will not work within limited time constraints.We need to fit the Sieve to our needs so that we run the Sieve only in that particular range.
The first prime is 2.We divide the starting number x=125 by 2 .We round off to smaller integer we get 62.We again multiply by 2 we get 124.
What is 124?it is the first smaller number than x that is divisible by the prime 2.
We start from 124,increment by 2 in each step and remove all elements between 125 and 140.
That is we remove 126,128,130,132,134,136,138,140.What we did was that we did the first step in traditional sieve but just offset the starting elements to the closest composite number less than the starting point of the range.
Next we do this with the 2nd smallest prime number 3.125/3=41.41*3=123.
We start from 123 go till 140 (inclusive) in steps of 3 and cut the numbers 126,129,132,135,138.
Next we do with 5.But from where do we get the prime numbers 2,3,5 and so on and how long do we need to do that?
We must first use traditional sieve to make a list of primes up to sqrt(N) where N is the larger of the range.
Then we will use this list of primes in the segmented sieve operation.
This will leave us with the prime numbers in the desired range.
Please re-read the above part a number of times and get this concept clear or revert back in case of any query.
*/
#include <iostream>
using namespace std;

int main()
{
    int t;
    int m,n;
    bool sieve[31623]={0};
    sieve[0]=1;
	sieve[1]=1;
    cin>>t;
    for(int i=2;i*i<=31623;i++)
    {
     if(sieve[i]==0)
     for(int j=i*i;j<=31623;j+=i)
      sieve[j]=1;
    }
    while(t--)
    {
     cin>>n>>m;
     bool seg[100001]={0};
	 seg[0]=1;
	 seg[1]=1;
     for(int i=2;i*i<=m;i++)
     {
      if(sieve[i]==0)
      {
       for(int j=i*(n/i);j<=m;j+=i)
        {
        	while(j<n)
        	 j+=i;
        	if(j<=31623)
        	 if(sieve[j]==0)
        	 seg[j]==0;
        	else
        	 seg[j-n+1]=1;
		}
      }
     }
     for(int i=n;i<=m;i++)
      if(seg[i-n+1]==0&&i!=1)
       cout<<i<<"\n";
     cout<<endl;
    }
	return 0;
}
