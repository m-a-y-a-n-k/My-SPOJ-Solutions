#include <iostream>

using namespace std;

int main()
{
    unsigned long long n,ans;
    while(cin>>n)
    {
        ans = 81*(n/9)+(n%9)*(n%9);
        cout<<ans<<endl;
    }
    return 0;
}
