#include <cstdio>
using namespace std;
int main()
{
	int t, s, x;
	scanf("%d%d%d", &t, &s, &x);
	puts(x == t || (x >= t + s && (!((x - t) % s) || !((x - t - 1) % s))) ? "YES" : "NO");
}
