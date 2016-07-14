#include<bits/stdc++.h>

using namespace std;
string code;
#define MAXN 5001
int dp[MAXN];
int limit;

int rek(int idx = 0) {
	if (idx > limit) return 1;

	if (dp[idx]) return dp[idx];

	if (code[idx] == '0') return 0;

	if (idx+1 < limit
		&& (code[idx] == '1' || (code[idx] == '2' && code[idx+1] <= '6'))) {
		if (code[idx+1] == '0')
			return dp[idx] = rek(idx+2);
		else
			return dp[idx] = rek(idx+1) + rek(idx+2);
	}
	else return dp[idx] = rek(idx+1);
}

int main()
{
    while (true)
    {
        getline(cin, code);
        if (code[0] == '0') break;
        limit = code.size();
        memset(dp, 0, sizeof dp);
        printf("%d\n", rek());
    }
    
    return 0;
}
