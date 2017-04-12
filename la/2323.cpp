#include<bits/stdc++.h>
using namespace std;
const int N = 2087;
typedef bitset<N> bs;
bs f,g,h,x;
char ans[N];
void print(const bs & v)
{
    int j = -1,tp = N-1;
    for (int i = v._Find_first(); i != v.size(); i = v._Find_next(i)) {
        while (++j < i) {
            ans[--tp] = '0';
            ans[--tp] = ' ';
        }
        ans[--tp] = '1';
        ans[--tp] = ' ';
    }
    printf("%d%s\n",j+1,ans+tp);
}
int main()
{
    int T;
    scanf("%d",&T);
    while(T--) {
        f.reset();
        g.reset();
        h.reset();
        int n,m,k;
        scanf("%d",&n);
        --n;
        for (int i = n; i >= 0; --i) {
            int c;
            while (!isdigit(c=getchar()));
            f[i] = c == '1';
        }
        scanf("%d",&m);
        --m;
        for (int i = m; i >= 0; --i) {
            int c;
            while (!isdigit(c=getchar()));
            g[i] = c == '1';
        }
        scanf("%d",&k);
        --k;
        for (int i = k; i >= 0; --i) {
            int c;
            while (!isdigit(c=getchar()));
            h[i] = c == '1';
        }
        x.reset();
        for (int i = f._Find_first(); i != f.size(); i = f._Find_next(i))
            x ^= g << i;
        int i = 0;
        while (x._Find_next(i) != x.size())
            i = x._Find_next(i);
        for (; i >= k; --i)
            if (x[i])
                x ^= h << (i - k);
        print(x);
    }
}
