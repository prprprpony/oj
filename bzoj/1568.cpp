#include <bits/stdc++.h>
using namespace std;
template<class val, class Cmp>
struct LiChaoSeg 
{
    const static int N = 5e4+87;
    struct line
    {
        val m,k;
        val operator () (val x)
        {
            return m * x + k;
        }
    } t[N*4];
    Cmp cmp;
    void init(line nil)
    {
        fill_n(t,N*4,nil);
    }
    void upd(line nf)
    {
        int o=1,l=0,r=N;
        while (r - l >= 1) {
            int m = (l + r) / 2;
            if (cmp(nf(m), t[o](m)))
                swap(nf,t[o]);
            if (r - l == 1)
                break;
            if (cmp(nf(l), t[o](l)))
                o+=o, r = m;
            else if (cmp(nf(r-1), t[o](r-1)))
                o+=o+1, l = m;
            else 
                break;
        }
    }
    val qry(int x)
    {
        int o=1,l=0,r=N;
        val ret=t[o](x);
        while (r - l > 1) {
            int m = (l + r) / 2;
            if (x <= m)
                o+=o, r = m;
            else
                o+=o+1, l = m;
            if (cmp(t[o](x), ret))
                ret = t[o](x);
        }
        return ret;
    }
};
LiChaoSeg< double,greater<double> > t;
int main()
{
    t.init({0,0});
    int n;
    scanf("%d",&n);
    while (n--) {
        char s[10];
        double k,m;
        int x;
        scanf("%s",s);
        if (s[0] == 'P') {
            scanf("%lf%lf",&k,&m);
            t.upd({m,k});
        } else {
            scanf("%d",&x);
            printf("%d\n", (int)(t.qry(x-1)/100));
        }
    }
}
