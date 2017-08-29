#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
#define PB push_back
#define SZ(a) ((int)(a).size())
#define ALL(a) (a).begin(), (a).end()
const int N = 1e6 + 5;
int sev[N];
vector<int> vp;
void pre()
{
	for (int i = 2; i < N; ++i) {
		if (!sev[i]) {
			sev[i] = i;
			vp.PB(i);
		}
		for (int j : vp) {
			if (i * 1LL * j >= N)
				break;
			sev[i * j] = j;
			if (j == sev[i])
				break;
		}
	}
}
int main()
{
	pre();
	int n;
	while (scanf("%d",&n) == 1 && n) {
		for (;n&1^1;n>>=1);
		vector<int> p;
		for (;n > 1; n /= sev[n])
			p.PB(sev[n]);
		sort(ALL(p));
		int d = 1;
		for (int i = 0, j = 0; i < SZ(p); d *= (j - i + 1), i = j)
			for (;j < SZ(p) && p[j] == p[i];++j);
		printf("%d\n",d - 1);
	}
}
