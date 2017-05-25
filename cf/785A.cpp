#include <bits/stdc++.h>
using namespace std;
char s[48763];
int main()
{
	int n,ans=0;
	scanf("%d",&n);
	while (n--) {
		scanf("%s",s);
		if (s[0] == 'T')
			ans += 4;
		else if(s[0] == 'C')
			ans += 6;
		else if (s[0] == 'O')
			ans += 8;
		else if (s[0] == 'D')
			ans += 12;
		else
			ans += 20;
	}
	printf("%d\n",ans);
}
