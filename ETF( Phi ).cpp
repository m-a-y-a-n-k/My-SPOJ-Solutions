#include <iostream>
#include <cstdio>
/*
   Euler totient function calculates phi(x) that how many numbers are co-prime to x in range of natural numbers 1 to x-1...
   It means for arbitrary y in set y belongs to 1 to x-1 gcd(x,y) = 1 .. No factors common

   As a matter of obvious fact , phi(x :- prime number) is x-1.. as primes have no factor except 1.

   Our approach is to use a function that computes and returns the result phi(x)...
   We develop a quicker solution for this..
   Naive approach would be to count all numbers uptill x-1 with gcd(y,x)=1.
   To get faster than this , we can count only for gcd(y,x) = 1 and subtract from total numbers i.e x - count
   So , we mark(remove) the first prime number that divides x and then it multiples less than x
    because x and all multiples have prime number the common factor..
    and keep doing so for all prime numbers less than x.
    But above solutions are still not feasible in terms of time-complexity O(x-1) worst case ..
	And prime numbers need to be generated in sieve() taking O(x) space..
	So , we keep reducing / factorising our original number by max power of each prime occurence.
	and subtract it from original number ..
	Storing our answer in result variable.
	Look at the implementation for the same.
*/

int phi(int n)
{
     int result = n;
     int i;
       for(i=2;i*i <= n;i++)
       {
         if (n % i == 0)
         result -= result / i;
         while (n % i == 0)          // use 25 to understand this part.
         n /= i;
       }
       if (n > 1)
       result -= result / n;        // result will be reult-1 ... but n and result become equal.
       return result;
}
int main()
{
    int t,num;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&num);
        printf("%d\n",phi(num));
    }
    return 0;
}

