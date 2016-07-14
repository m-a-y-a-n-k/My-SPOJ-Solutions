#include <bits/stdc++.h>

using namespace std;

#define MAX 100000

struct Tree 		//Node present in a SegTree
{
	long long ms;           //max sum of two distinct indexes in range
	long long mv;			//max value so far in range
};

int arr[MAX+1];
Tree seg[4*MAX+1];

void build(int u,int v,int node)			//build initialized with (0,N-1,0)
{
	//builds a Seg-tree with special property to store max value and sum in a range
	if(u==v)
	{
		seg[node].mv=seg[node].ms=arr[u];
		return ;
	}
	build(u,(u+v)/2,2*node);
	build((u+v)/2+1,v,2*node+1);
	Tree left=seg[2*node];
	Tree right=seg[2*node+1];
	// maintain special property
	seg[node].ms=max(left.ms,max(right.ms,right.mv+left.mv));
	seg[node].mv=max(left.mv,right.mv);
}

void update(int u,int v,int node,int K,int pos)
{
	if(u==v&&u==pos)
	{
		seg[node].mv=seg[node].ms=K;		//changing leaf node data if need be
		return ;
	}
	if(pos<=(u+v)/2)
	{
		update(u,(v+u)/2,node*2,K,pos);			//if left sub-seg-tree needs to update
	}
	if(pos>(u+v)/2)
	{
		update(1+(v+u)/2,v,node*2+1,K,pos);			//if right sub-seg-tree needs to update
	}
	// maintaining special property of seg-tree
	Tree left=seg[node*2];
	Tree right=seg[node*2+1];
	seg[node].ms=max(left.ms,max(right.ms,right.mv+left.mv));
	seg[node].mv=max(left.mv,right.mv);
}

Tree query(int u,int v,int node,int x,int y)	//To answer a query of max-sum in range x,y
{
	if(v<x||y<u||x>y)					// If seg-node range is disjoint to given range
	{
		return ((Tree){0,0});
	}
	if(x<=u&&v<=y)				//If seg-node range is completely enclosed inside given range
	{
		return seg[node];
	}
	//Maintain special seg-tree property and return Seg-node explicitly created to answer the query
	Tree left=query(u,(u+v)/2,2*node,x,y);
	Tree right=query((u+v)/2+1,v,2*node+1,x,y);
	return ((Tree){(max(left.ms,max(right.ms,left.mv+right.mv))),(max(left.mv,right.mv))});
}

int main()
{
	int N,Q,i=0,x,y;
	scanf("%d",&N);
	for(i=0;i<N;i++)
	{
		scanf("%d",&arr[i]);
	}
	build(0,N-1,1);
	scanf("%d",&Q);
	char op;
	while(Q--)
	{
	    getchar();
		scanf("%c%d%d",&op,&x,&y);
		if(op=='Q')
		{
			printf("%lld\n",query(0,N-1,1,x-1,y-1).ms);
		}
		else
		{
			update(0,N-1,1,y,x-1);
		}
	}
	return 0;
}
