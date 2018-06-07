#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
#define F first
#define S second
int main()
{
    int q,x;
    cin >> q >> x;
    pii p[105];
    for (int i = 0; i < q; ++i) {
        cin >> p[i].F >> p[i].S;
        p[i].S -= p[i].F;
    }
    for (int i = 0; i < 12; ++i) {
        int ch = -1, mx = 0;
        for (int j = 0; j < q; ++j)
            if (p[j].F <= x && p[j].S > mx) {
                mx = p[j].S;
                ch = j;
            }
        if (ch < 0)
            break;
        x += mx;
    }
    cout << x << endl;
}
