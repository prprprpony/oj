#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int kase;
void solve(int n,ll k,char f,char s,char t)
{
    ll v = (1LL<<(n-1))-1;
    if (k <= v)
        solve(n-1,k,f,t,s);
    else if (k == v + 1)
        printf("Case %d: %d %c %c\n",++kase,n,f,t);
    else
        solve(n-1,k-v-1,s,f,t);
}
int main()
{
    ll k;
    int n;
    while (scanf("%lld%d",&k,&n) == 2 && k && n)
        solve(n,k,'A','B','C');
}
