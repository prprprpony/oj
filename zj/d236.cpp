#include <cstdio>
using namespace std;
/*
a^2 + b^2 = c^2
a + b + c = 1000
a + b = 1000 - c
a^2 + b^2 + 2ab = c^2 -2000c + 1000000
ab = 500000 - 1000c
*/
int main()
{
    for (int c = 334; c <= 998; ++c) {
        int ab = 500000 - 1000 * c;
        for (int a = 1; a * a <= ab; ++a)
            if (!(ab % a)) {
                int b = ab / a;
                if (a + b + c == 1000) {
                    printf("%d\n", a * b * c);
                    return 0;
                }
            }
    }
}
