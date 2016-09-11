#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
// const int maxn = 1e8;
#define rep(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))
#define pb push_back
#define eb emplace_back
#define X first
#define Y second
#ifdef __unix__
#define LLD "%lld"
#else
#define LLD "%I64d"
#endif
inline bool RI(int & ___a) {return scanf("%d", &___a) == 1;}
inline bool RL(ll & ___a) {return scanf(LLD, &___a) == 1;}
inline void PI(int ___a) {printf("%d\n", ___a);}
inline void PL(ll ___a) {printf(LLD"\n", ___a);}
int main()
{
	int x, y;
	RI(x), RI(y);
	int a = y, b = y;
	int cnt = 0;
	while (b < x) {
		++cnt;
		a += b - 1;
		swap(a, b);
	}
	PI(cnt + 2);
}
