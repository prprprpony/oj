#include<bits/stdc++.h>
using namespace std;
void exgcd(int a,int&x,int b,int&y,int&g)
{
    if (b) {
        exgcd(b,y,a%b,x,g);
        y-=a/b*x;
    } else {
        x=1;
        y=0;
        g=a;
    }
}
inline int cl(int a,int b)
{
    assert(b);
    if (!a) return 0;
    if (a > 0 == b > 0) {
        a = abs(a), b = abs(b);
        return (a+b-1)/b;
    } else {
        a = abs(a), b = abs(b);
        return -(a/b);
    }
}
int main()
{
    int a,b,c,d;
    cin >> a >> b >> c >> d;
    int w=d-b,x0,y0,g;
    exgcd(a,x0,c,y0,g);
    if (w%g) {
        cout << "-1\n";
        return 0;
    }
    w/=g;
    int a_=a/g,c_=c/g;
    x0*=w,y0*=w;
    int x = x0+max(cl(-x0,c_),cl(y0,a_))*c_;
    cout << a*x+b << '\n';
}
