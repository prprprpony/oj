#include<bits/stdc++.h>
using namespace std;
#define ALL(a) begin(a), end(a)
#define REP(i,a,b) for (int i(a); i < (b); ++i)
#define RP(i,n) REP(i,0,n)
int main()
{
    int n;
    cin >> n;
    vector<int> x(n), y(n);
    for (int & a : x)
        cin >> a;
    for (int & a : y)
        cin >> a;
    sort(ALL(x));
    sort(ALL(y));
    RP(i,n)
        if (x[i] > y[i]) {
            cout << "NE\n";
            return 0;
        }
    cout << "DA\n";
}
