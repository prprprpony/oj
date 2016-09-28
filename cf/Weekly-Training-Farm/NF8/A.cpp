#include <cstdio>
using namespace std;
int main()
{
	int K, N;
	scanf("%d%d", &K, &N);
	puts(K % N ? "No" : "Yes");
}
