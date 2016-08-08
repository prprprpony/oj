#include <cstdio>
using namespace std;
int main()
{
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; ++i)
		printf("I %s %s", i & 1 ? "love" : "hate", i != n - 1 ? "that " : "it\n");
}
