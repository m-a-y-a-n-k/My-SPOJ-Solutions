#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>

using namespace std;

int checks[100101]={0};

int main()
{
    ios_base::sync_with_stdio(false);
    int N,M,l,r,i,j;
    cin>>N;
    string s;
    char swp;
    char one[N+1],two[N+1];
    long long sum=0;
    getline(cin,s);
    getline(cin,s);
    M = s.size();
    if(M>N)
    {
        for(i=0;i<M;i++)
        {
        if(s[i]=='\\')
        {
            if(s[i+1]=='t')
            {
                s[i] = '\t';
                for(j=i+1;j<M;j++)
                {
                    s[j]=s[j+1];
                }
                --M;
            }
            else if(s[i+1]=='r')
            {
                s[i] = '\r';
                for(j=i+1;j<M;j++)
                {
                    s[j]=s[j+1];
                }
                --M;
            }
            else if(s[i+1]=='\\')
            {
                s[i] = '\\';
                for(j=i+1;j<M;j++)
                {
                    s[j]=s[j+1];
                }
                --M;
            }
            else if(s[i+1]=='x'&&s[i+2]=='0')
            {
                if(s[i+3]=='b')
                {
                    s[i]='\x0b';
                    for(j=i+1;j<M;j++)
                    {
                        s[j]=s[j+3];
                    }
                    M = M-3;
                }
                else if(s[i+3]=='c')
                {
                    s[i]='\x0c';
                    for(j=i+1;j<M;j++)
                    {
                        s[j]=s[j+3];
                    }
                    M = M-3;
                }
            }
            }
        }
    }
    for(i=0;i<M;i++)
        one[i]=s[i];
    //cout<<one<<endl;
    getline(cin,s);
    M = s.size();
    if(M>N)
    {
        for(i=0;i<M;i++)
        {
        if(s[i]=='\\')
        {
            if(s[i+1]=='t')
            {
                s[i] = '\t';
                for(j=i+1;j<M;j++)
                {
                    s[j]=s[j+1];
                }
                --M;
            }
            else if(s[i+1]=='r')
            {
                s[i] = '\r';
                for(j=i+1;j<M;j++)
                {
                    s[j]=s[j+1];
                }
                --M;
            }
            else if(s[i+1]=='\\')
            {
                s[i] = '\\';
                for(j=i+1;j<M;j++)
                {
                    s[j]=s[j+1];
                }
                --M;
            }
            else if(s[i+1]=='x'&&s[i+2]=='0')
            {
                if(s[i+3]=='b')
                {
                    s[i]='\x0b';
                    for(j=i+1;j<M;j++)
                    {
                        s[j]=s[j+3];
                    }
                    M = M-3;
                }
                else if(s[i+3]=='c')
                {
                    s[i]='\x0c';
                    for(j=i+1;j<M;j++)
                    {
                        s[j]=s[j+3];
                    }
                    M = M-3;
                }
            }
            }
        }
    }
    for(i=0;i<M;i++)
        two[i]=s[i];
    //cout<<two<<endl;
    cin>>M;
    while(M--)
    {
        cin>>l>>r;
        checks[l]++;
        checks[r+1]++;
    }
    for(i=0;i<N;i++)
    {
        sum = sum + checks[i];
        if(sum%2==1)
        {
            swp = one[i];
            one[i] = two[i];
            two[i] = swp;
        }
    }
    for(i=0;i<N;i++)
    {
        if(one[i]=='\t')
            cout<<"\\t";
        else if(one[i]=='\r')
            cout<<"\\r";
        else if(one[i]=='\x0b')
            cout<<"\\x0b";
        else if(one[i]=='\x0c')
            cout<<"\\x0c";
        else
            cout<<one[i];
    }
    cout<<endl;
    for(i=0;i<N;i++)
    {
        if(two[i]=='\t')
            cout<<"\\t";
        else if(two[i]=='\r')
            cout<<"\\r";
        else if(two[i]=='\x0b')
            cout<<"\\x0b";
        else if(two[i]=='\x0c')
            cout<<"\\x0c";
        else
            cout<<two[i];
    }
    cout<<endl;
    return 0;
}
