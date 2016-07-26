#include <cstdio>
#include <cctype>
using namespace std;
int main()
{
	int c;
	int ans = 1;
	while ((c = getchar()) != EOF)
		if (isupper(c))
			++ans;
	printf("%d\n", ans);
}
