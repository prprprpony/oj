#include <cstdio>
using namespace std;

int main()
{
    int k;
    while (scanf("%d%*d",&k) != EOF) {
        int s[k], r[k], ans = 0;
        for (int i = 0; i < k; i++)
            scanf("%d", &s[i]);
        for (int i = 0; i < k; i++)
            scanf("%d", &r[i]);
        for (int i = 0; i < k - 1; i++)
            for (int j = i + 1; j < k; j++)
                if ((s[i] > s[j] && r[i] < r[j]) || (s[i] < s[j] && r[i] > r[j]))
                    ans++;
        printf("%d\n",ans);
    }

    return 0;
}
