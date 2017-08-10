#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
#define ALL(a) (a).begin(),(a).end()
const int N = 10000000 + 6;
bool sev[N];
int main()
{
	vector<int> p;
	for (int i = 2; i < N; ++i) {
		if (!sev[i])
			p.push_back(i);
		for (int j : p) {
			if (i * j >= N)
				break;
			sev[i * j] = 1;
			if (i % j == 0)
				break;
		}
	}
	int T;
	scanf("%d",&T);
	while (T--) {
		int a,b;
		scanf("%d%d",&a,&b);
		if (a > b)
			swap(a,b);
		printf("%d\n",(int)(upper_bound(ALL(p),b) - upper_bound(ALL(p),a-1)));
	}
}
