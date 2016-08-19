#include <cstdio>
using namespace std;
const int MAXN = 5e5 + 689;
int p[MAXN];
int foe[MAXN];
char cmd[2][16];
int find(int x) {return x == p[x] ? x : p[x] = find(p[x]);}
int main()
{
	int N;
	scanf("%d", &N);
	for (int i = 1; i <= N; ++i)
		p[i] = i;
	while (scanf("%s", cmd[0]) == 1) {
		int a, b;
		scanf("%s%s%d%d", cmd[0], cmd[1], &a, &b);
		a = find(a), b = find(b);
		foe[a] = find(foe[a]), foe[b] = find(foe[b]);
		bool f = cmd[1][0] == 'f';
		switch (cmd[0][0]) {
		case 'a':
			//assign
			if (f && a != foe[b] && b != foe[a]) {
				p[a] = b;
				if (foe[a] && foe[b])
					p[foe[a]] = foe[b];
				else
					foe[b] = foe[a] ? foe[a] : foe[b];
				if (foe[b])
					foe[foe[b]] = b;
			} else if (!f && a != b && (foe[a] != foe[b] || (!foe[a] && !foe[b]))) {
				if (foe[b])
					p[foe[b]] = a;
				if (foe[a])
					p[foe[a]] = b;
				foe[a] = b;
				foe[b] = a;
			} else {
				puts("angry");
			}
			break;
		case 'y':
			//query
			puts((f ? a == b : foe[a] == b) ? "yeap" : "nope");
			break;
		}
	}
}
