#include<bits/stdc++.h>
using namespace std;
#define REP(i,a,b) for (int i(a),_B(b);i<_B;++i)
const int N = 287;
int t[N<<2];
void bld(int o,int l,int r)
{
    if ((t[o] = r-l) == 1)
        return;
    int m=(l+r)/2;
    bld(o+o+1,l,m);
    bld(o+o+2,m,r);
}
int upd(int o,int l,int r,int v)
{
    --t[o];
    if (r-l==1)
        return l;
    int m=(l+r)/2;
    if (t[o+o+1]>=v)
        return upd(o+o+1,l,m,v);
    else
        return upd(o+o+2,m,r,v-t[o+o+1]);
}
int main()
{
    int n,k;
    scanf("%d%d",&n,&k);
    bld(0,0,n);
    int j = 0;
    REP(i,0,k) {
        int a;
        scanf("%d",&a);
        j=(j+a)%(n-i);
        printf("%d%c",upd(0,0,n,j+1)+1," \n"[i==k-1]);
    }
}
