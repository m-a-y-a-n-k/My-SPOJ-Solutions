#include <iostream>
#include <cstdio>
#include <queue>
#include <stack>

using namespace std;

int main()
{
	int N,x;
	
	bool flag;
	
	//check order before inserting element if order lost pop from stack and push to output queue
	
	while(scanf("%d",&N)==1 && N)
	{
		flag=true;
		stack <int> order;
		queue <int> input;
		queue <int> output;
		while(N--)
		{
			scanf("%d",&x);
			input.push(x);
		}
		if(input.empty())
		{
			printf("no\n");
			continue;
		}
		order.push(100000);
		output.push(0);
		while(!input.empty())
		{
			if(input.front()<order.top())
			{
				order.push(input.front());
				input.pop();
			}
			else
			{
				if(order.top()<output.back())
				{
					flag=false;
					break;
				}
				output.push(order.top());
				order.pop();
			}
		}
		while(!order.empty())
		{
			if(order.top()<output.back())
			{
				flag=false;
				break;
			}
			output.push(order.top());
			order.pop();
		}
		if(flag==true)
			printf("yes\n");
		else
			printf("no\n");
		while(!input.empty())
			input.pop();
		while(!output.empty())
			output.pop();
	}
	return 0;
}