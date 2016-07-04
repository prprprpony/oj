#include <cstdio>
#include <cctype>
using namespace std;
const int maxn = 1.64e4;
char s[maxn];
int main()
{
    while (fgets(s, sizeof(s), stdin)) {
        int v = 0;
        for (int i = s[0] == '-' ? 1 : 0; isdigit(s[i]); ++i)
            v = (v + s[i] - '0') % 3;
        puts(v ? "no" : "yes");
    }
}
