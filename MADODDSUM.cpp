#include <iostream>

using namespace std;

int main()
{
    unsigned long long a,b,ans;
    cin>>a>>b;
        a = a>>1;
        b = (b-1)>>1;
        a = 2*a + 1;
        b = 2*b + 1;
        ans = (b-a)>>1;
        ans = (ans + 1) * ( a + ans );
    cout<<ans<<endl;
    return 0;
}
