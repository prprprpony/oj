#include <cstdio>
using namespace std;
int main()
{
    int a;
    scanf("%d", &a);
    while (a && a % 10 == 0)
        a /= 10;
    do {
        putchar(a % 10 + '0');
    } while (a /= 10);
    putchar('\n');
}
