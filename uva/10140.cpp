#include<bits/stdc++.h>
using namespace std;
const int N = 1e5;
bool sev[N];
#define PB push_back
#define ALL(a) begin(a), end(a)
#define SZ(a) ((int)a.size())
vector<int> p;
void bld()
{
    sev[0] = sev[1] = 1;
    for(int i = 2; i < N; ++i) {
        if (!sev[i])
            p.PB(i);
        for (int j : p) {
            if (i * j >= N) break;
            sev[i * j] = 1;
            if (i % j == 0) break;
        }
    }
}
bool isp(int x)
{
    for (int i : p) {
        if (i * 1LL * i > x) return 1;
        if (x % i == 0) return 0;
    }
}
int main()
{
    bld();
	int l,u;
	while(scanf("%d%d",&l,&u) == 2) {
        int x=0,y=1e9,z=0,w=0;
        int lp=0;
        for (unsigned int i = l; i <= u; ++i) {
            bool ok = i < N ? !sev[i] : isp(i);
            if (!ok) continue;
            if (lp) {
                if (i-lp < y-x)
                    x = lp, y = i;
                if (i-lp > w-z)
                    z = lp, w = i;
            }
            lp = i;
        }
        if (x)
            printf("%d,%d are closest, %d,%d are most distant.\n",x,y,z,w);
        else
            puts("There are no adjacent primes.");
	}
}
