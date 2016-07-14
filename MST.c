#include <stdio.h>
#include <stdlib.h>

int A,B,i,j;

typedef struct Sorted_links
{
    int u,v;
    int wt;
}Edge;

int findSet(int x,int *head,int *rank)
{
    if(x==head[x])
    {
        return x;
    }
    rank[x]=0;
    return head[x]=findSet(head[x],head,rank);
}

char Unite(int s,int r,int *rank,int *head)
{
    int ps=findSet(s,head,rank);
    int pr=findSet(r,head,rank);
    if(ps==pr)
    {
        return 'n';
    }
    if(rank[ps]>=rank[pr])
    {
        head[pr]=ps;
        rank[ps]++;
    }
    if(rank[ps]<rank[pr])
    {
        head[ps]=pr;
        rank[pr]++;
    }
    return 'y';
}

void MSTKruskal(Edge *E,int *rank,int *head)
{
    Edge temp;
	for(i=0; i<B; i++)
	{
		for(j=i; j<B; j++)
		{
			if(E[i].wt>E[j].wt)
			{
				temp=E[i];
				E[i]=E[j];
				E[j]=temp;
			}
		}
	}
	j=0;
    for(i=0;i<B;i++)
    {
        if(Unite(E[i].u,E[i].v,rank,head)=='y')
        {
            j+=E[i].wt;
        }
    }
    printf("%d\n",j);
}

int main()
{
    scanf("%d%d",&A,&B);
    Edge E[B];
    int head[A],rank[A];
    for(i=0;i<A;i++)
    {
        head[i]=i;
        rank[i]=1;
    }
    for(i=0;i<B;i++)
    {
        scanf("%d%d%d",&E[i].u,&E[i].v,&E[i].wt);
        E[i].u--;E[i].v--;
    }
    MSTKruskal(&E[0],rank,head);
    return 0;
}
