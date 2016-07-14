#include <iostream>
using namespace std;

/*
"You all have to make teams and go on a hunt for Bananas.May the force be with you !
The team that returns with the highest number of Bananas will be rewarded with as many gold coins as the number of Bananas with them."

Given there are N monkeys in the kingdom. Each monkey who wants to team up with another monkey has to perform a ritual.
Given total M rituals are performed. Each ritual teams up two monkeys.
If Monkeys A and B teamed up and Monkeys B and C teamed up, then Monkeys A and C are also in the same team.

You are given an array A where Ai is the number of bananas i'th monkey gathers.

Find out the number of gold coins that our Monk should set aside for the prize.

Input:
First line contains an integer T. T test cases follow. First line of each test case contains two space-separated N and M.
M lines follow. Each of the M lines contains two integers Xi and Yi, the indexes of monkeys that perform the i'th ritual.
Last line of the test-case contains N space-separated integer constituting the array A.

Output:
Print the answer to each test case in a new line.
Constraints:
1 ≤ T ≤ 10
1 ≤ N ≤ 1e5
0 ≤ M ≤ 1e5
0 ≤ Ai ≤ 1e12*/

int dsh[100001];					// stores head of monkey 1 to 100000
long long banana[100001];			//bananas collected by monkey 1 to 100000

struct join
{
	int x;
	int y;
}E[100001];				// monkey x and y are joined ( x and y can be same so 1e5 joins)

int head(int x)
{	
	if(dsh[x]==x)					//if monkey x is head
		return x;
	return dsh[x]=head(dsh[x]);			// finds head of monkey x and cache it
}

void uni(int x,int y)
{
	int i=head(x);						// i is head of monkey x 
	int j=head(y);						// j is head of monkey y
	if(i==j)			// if heads of x and y are same they are already unified
		return;
	dsh[i]=j;								// j is made head of i
	banana[j]+=banana[i];					// j takes all bananas of i 
}	

int main()
{
	int T,N,M,i;
	cin>>T;					//testcases
	while(T--)
	{
		cin>>N>>M;				//total monkeys
		for(i=0;i<=N;i++)
		{
			dsh[i]=i;				// monkey i is head yet
			banana[i]=0;			//monkey i has no banana yet
		}
		i=1;
		while(i<=M)
		{
			cin>>E[i].x>>E[i++].y;			//storing Queries to use later
		}
		i=1;
		while(i<=N)
		{
			cin>>banana[i++];			//bananas monkey i collects
		}
		i=1;
		while(i<=M)
		{
			uni(E[i].x,E[i++].y);	//join x and y now(that's why query was stored earlier)
		}
		i=1;
		//There is no zeroth monkey actually :) 
		while(i<=N)
		{
			banana[0]=max(banana[0],banana[i++]);		
		}
		cout<<banana[0]<<endl;
	}	
    return 0;
}
