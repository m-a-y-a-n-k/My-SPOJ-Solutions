#include <iostream>
#include <vector>
#include <queue>
#include <cstdio>
using namespace std;
/*
Our Monk loves candy!
While taking a stroll in the park, he stumbled upon N Bags with candies. The i'th of these bags contains Ai candies.
He picks up a bag, eats all the candies in it and drops it on the ground. But as soon as he drops the bag, the number of candies in the bag increases magically! Say the bag that used to contain X candies (before eating), now contains [X/2] candies! ,where [x] is the greatest integer less than x (Greatest Integer Function).
Amazed by the magical spell, Monk can now have a lot more candies! But he has to return home in K minutes. In a single minute,Monk can consume all the candies in a single bag, regardless of the number of candies in it.
Find the maximum number of candies that Monk can consume.

Input:
First line contains an integer T. T test cases follow.
First line of each test case contains two space-separated integers N and K.
Second line of each test case contains N space-separated integers,the number of candies in the bags.

Output:
Print the answer to each test case in a new line.

*/
 //USE priority queue --> sorting will take O(T*N*logN*K)
 /*
   The priority queue will access first member which is greatest priority(RANK/KEY VALUE).
   Real world model -- V.I.P standing in a long queue will be first addressed.
   Application --> A TIME SHARING SYSTEM.
   ********************************************************
   Now coming to our problem
   pq will automatically rank a number but data structure is original
   Top element of pq is greatest..Thus no need to sort.
   temp = top priority element
   Now POP this element and push temp/2.
   PRIORITY QUEUE approach reduces to
 */
int main()
{
    int T,K,N,i;
    scanf("%d",&T);
    while(T--)
    {
    	scanf("%d%d",&N,&K);
    	long long ans=0;
    	vector <int> v(N);
    	priority_queue <int> pq;
    	for(i=0;i<N;i++)
    	{
    		cin>>v[i];
    		pq.push(v[i]);
    	}
    	 while(K--)
    	 {
    		int k=pq.top();
    		ans+=k;
    		pq.pop();
    		pq.push(k/2);
    	 }
    	cout<<ans<<endl;
    }
    return 0;
}

