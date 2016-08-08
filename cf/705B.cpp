#include <cstdio>
using namespace std;
int main()
{
	int n, sum = 0;
	scanf("%d", &n);
	while (n--) {
		int a;
		scanf("%d", &a);
		printf("%d\n", 2 - (sum ^= ((a & 1) ^ 1)));
	}
}
