#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
#define F first
#define S second
const int N = 106;
pii x[N], y[N];
vector<int> gx[N];
int vy[N], my[N];
bool mat(int a)
{
    for (int b : gx[a]) if (!vy[b]) {
        vy[b] = 1;
        if (my[b] == -1 || mat(my[b])) {
            my[b] = a;
            return 1;
        }
    }
    return 0;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i)
        cin >> x[i].F >> x[i].S;
    for (int i = 0; i < n; ++i)
        cin >> y[i].F >> y[i].S;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (x[i].F < y[j].F && x[i].S < y[j].S) {
                gx[i].push_back(j);
            }
        }
    }
    int ans = 0;
    memset(my,-1,sizeof(my));
    for (int i = 0; i < n; ++i) {
        memset(vy,0,sizeof(vy));
        ans += mat(i);
    }
    cout << ans << endl;
}
