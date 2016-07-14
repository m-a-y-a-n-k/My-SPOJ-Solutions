#include <bits/stdc++.h>

using namespace std;

char str[10000001];

int main()
{
    ios_base::sync_with_stdio(false);
    int i,j,k,len,T,x;
    bool next;
    cin>>T;
    while(T--)
    {
        next=false;
        cin>>len;
        for(i=0;i<len;i++)
        {
            cin>>x;
            str[i]=x+'0';
        }
        str[i]='\0';
        for(i=len-1;i>0;i--)
        {
            if(str[i]>str[i-1])
            {
                next=true;
                for(j=len-1;j>=i;j--)
                {
                    if(str[j]>str[i-1])
                    {
                        swap(str[i-1],str[j]);
                        break;
                    }
                }
            }
            if(next==true)
            {
                break;
            }
        }
        if(next==false)
            cout<<"-1"<<endl;
        else
        {
            sort(str+i,str+len);
			for(i=0;i<len;i++)
            	cout<<str[i];
			cout<<endl;
        }
    }
    return 0;
}
