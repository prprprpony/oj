#include<bits/stdc++.h>
using namespace std;
bool le(int x,int y)
{
    cout << "1 " << x << ' ' << y << endl;
    string s;
    cin >> s;
    return s == "TAK";
}
int f(int l,int r)
{
    if (r - l == 0)
        return l;
    int m = l+r>>1;
    if (le(m,m+1))
        return f(l,m);
    else
        return f(m+1,r);
}
int main()
{
    int n,k;
    cin >> n >> k;
    int x = f(1,n);
    int y = 1;
    if (x + 1 <= n)
        y = f(x+1,n);
    if (!le(y,x))
        y = f(1,x-1);
    cout << 2 << ' ' << x << ' ' << y << endl;
}
