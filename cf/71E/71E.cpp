#include <bits/stdc++.h>
using namespace std;
const char * pt[] = {"Pony","H","He","Li","Be","B","C","N","O","F","Ne","Na","Mg","Al","Si","P","S","Cl","Ar","K","Ca","Sc","Ti","V","Cr","Mn","Fe","Co","Ni","Cu","Zn","Ga","Ge","As","Se","Br","Kr","Rb","Sr","Y","Zr","Nb","Mo","Tc","Ru","Rh","Pd","Ag","Cd","In","Sn","Sb","Te","I","Xe","Cs","Ba","La","Ce","Pr","Nd","Pm","Sm","Eu","Gd","Tb","Dy","Ho","Er","Tm","Yb","Lu","Hf","Ta","W","Re","Os","Ir","Pt","Au","Hg","Tl","Pb","Bi","Po","At","Rn","Fr","Ra","Ac","Th","Pa","U","Np","Pu","Am","Cm","Bk","Cf","Es","Fm"};
const int maxn = 17;
char t[4];
int x[maxn], y[maxn];
int a[1 << maxn];
int dp[1 << maxn];
int c[1 << maxn];
int get_an(char * s)
{
	for (int i = 1; i <= 100; ++i)
		if (!strcmp(s, pt[i]))
			return i;
	assert(2 + 2 == 5);
}
int main()
{
	int n, k;
	scanf("%d%d", &n, &k);
	for (int i = 0; i < n; ++i) {
		scanf("%s", t);
		x[i] = get_an(t);
	}
	for (int i = 0; i < k; ++i) {
		scanf("%s", t);
		y[i] = get_an(t);
	}
	for (int S = 1; S < (1 << n); ++S)
		a[S] = a[S ^ (S & -S)] + x[__lg(S & -S)];
	for (int S = 1; S < (1 << n); ++S)
		for (int SS = S; SS; SS = (SS - 1) & S) 
			if (a[SS] == y[dp[S^SS]] && dp[S ^ SS] + 1 > dp[S]) {
				dp[S] = dp[S ^ SS] + 1;
				c[S] = SS;
			}
	if (dp[(1 << n) - 1] != k) {
		puts("NO");
	} else {
		puts("YES");
		for (int S = (1 << n) - 1; S; S ^= c[S]) {
			int SS = c[S];
			printf("%s", pt[a[SS & -SS]]);
			for (SS ^= (SS & -SS); SS; SS ^= (SS & -SS))
				printf("+%s", pt[a[SS & -SS]]);
			printf("->%s\n", pt[y[dp[S]-1]]);
		}
	}
}
