#include <bits/stdc++.h>

using namespace std;

 void PrefixComputer( string P, int *prefix) {

    int p = P.size();
    int k = -1;
    prefix[0] = 0;

    for( int q = 1 ; q < p; q++ ) {

        while( k >=0 && P[k+1] != P[q] ) {
            k = prefix[k]-1;
        }
        if( P[k+1] == P[q]) {
            k = k+1;
        }
        prefix[q] = k;
    }

}

void KMP( string Pattern, string Text, int *prefix ) {

    int P = pattern.size();
    int T = text.size();
    PrefixComputer(Pattern,prefix);
    int q = -1;

    for( i = 0; i < T; i++ ) {
        while( q >= 0 && Pattern[q+1] != Text[i] ) {
            q = prefix[q] - 1;
        }
        if( Pattern[q] == Text[i] ) {
            q = q + 1;
        }
        if( q == m - 1) {
            cout << "Pattern occurs with shift" << i - m;
            q = prefix[q];
        }
    }
}

int main() {

    string pattern,text;
    int *prefix;
    cout << "Enter Text" << endl;
    cin >> text;

    cout << "Enter pattern" << endl;
    cin >> pattern;

    prefix = new int[P+1];
    KMP(pattern,text,prefix);

    return 0;
}
