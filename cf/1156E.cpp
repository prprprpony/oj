#include<bits/stdc++.h>
using namespace std;
const int N = 2e5+87;
int a[N],p[N];
set<int> s[N];
int find(int x) {return p[x] < 0 ? x : p[x] = find(p[x]);}
void meld(int x,int y)
{
    x = find(x);
    y = find(y);
    if (x == y)
        return;
    if (-p[x] > -p[y])
        swap(x,y);
    p[x] = y;
    s[y].insert(begin(s[x]),end(s[x]));
    s[x].clear();
}
int main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        int x;
        cin >> x;
        a[x] = i;
    }
    int ans = 0;
    for (int i = 1; i <= n; ++i) {
        int j = a[i];
        p[j] = -1;
        s[j] = {i};
        int l = j, r = j;
        if (p[j-1])
            l = find(j-1);
        if (p[j+1])
            r = find(j+1); 
        if (l != j && r != j) {
            if (-p[l] > -p[r])
                swap(l,r);
            for (int x : s[l])
                ans += s[r].count(i-x);
        }
        meld(j,l);
        meld(j,r);
    }
    cout << ans << endl;
}
