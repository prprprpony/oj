#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))
#define pb push_back
#define eb emplace_back
#define X first
#define Y second
inline bool RI(int & ___a) {return scanf("%d", &___a) == 1;}
inline bool RL(ll & ___a) {return scanf("%I64d", &___a) == 1;}
const char * dir = "LRUD";
int cnt[4];
inline int getid(int c)
{
	for (int i = 0; dir[i]; ++i)
		if (c == dir[i])
			return i;
}
int main()
{
	int c;
	int tot = 0;
	while ((c = getchar()) != '\n' && c != EOF)
		++cnt[getid(c)], ++tot;
	if (cnt[0] > cnt[1])
		swap(cnt[0], cnt[1]);
	if (cnt[2] > cnt[3])
		swap(cnt[2], cnt[3]);
	if (tot & 1)
		puts("-1");
	else {
		int d1 = cnt[1]-cnt[0], d2 = cnt[3]-cnt[2];
		int mn = min(d1,d2), mx = max(d1, d2);
		printf("%d\n", mn + (mx - mn) / 2);
	}
}
