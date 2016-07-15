#include <cstdio>
#include <unordered_map>
using namespace std;
unordered_map<int,int> h_cache;
unordered_map<int,int> f_cache;
int g(int z) {return z <= 2 ? z * z - 1 : 2;}
int h(int y) {return y < 2 ? -1 : h_cache.count(y) ? h_cache[y] : h_cache[y] = 2 + h(y - 1) - h(y - 2);}
int f(int x) {return f_cache.count(x) ? f_cache[x] : f_cache[x] = x > h(x) ? f(x - 1) - h(x) : x < h(x) ? f(g(x)) - g(x) : 1;}
int main()
{
	int x;
	scanf("%d", &x);
	printf("%d\n", f(x));
}
