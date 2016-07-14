#include <iostream>
#include <cmath>
using namespace std;
#define max 1000001

int count;

void mergesort(int *arr,int p,int m,int r)
{
  int x=m-p+1,y=r-m;
  int L[x+2],R[y+2];
  int i,j,k;
  for(i=1;i<=x;i++)
   L[i]=arr[i+p-1];
  for(j=1;j<=y;j++)
   R[j]=arr[j+m];
  L[x+1]=max;
  R[y+1]=max;
  i=j=1;
  k=p;
  while(k<=r)
  {
   if(L[i]<=R[j])
   {
    arr[k]=L[i];
     i++;
   }
   else
   {
    arr[k]=R[j];
    int d=x-i+1;
     count=count+d;
    j++; 
   }
   k++;
  }
}

void splitsort(int *arr,int p,int r)
{
   if(p<r)
   {
     int m=p+(r-p)/2;
     splitsort(arr,p,m);
     splitsort(arr,m+1,r);
     mergesort(arr,p,m,r);
   }
}

int main() 
{
	int T,N;
	cin>>T;
	while(T--)
	{
		cin>>N;
		int A[N],i;
		count=0;
		for(i=0;i<N;i++)
		 cin>>A[i];
		splitsort(A,0,N-1);
		cout<<count<<endl;
	}
	return 0;
}