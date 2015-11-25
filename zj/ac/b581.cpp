#include <cstdio>
#include <cctype>
using namespace std;
int main()
{
    char buf[8000];
    int t;
    int ans;
    int n;
    scanf("%d ", &t);
    while (t--) {
        fgets(buf, sizeof(buf), stdin);
        ans = 0;
        for (char *it = buf; *it != '\0'; ) {
            sscanf(it, "%d", &n);
            ans += n;
            while ((*it) != ' ' && (*it) != '\n')
                it++;
            it++;
        }
        printf("%d\n", ans);
    }

    return 0;
}
