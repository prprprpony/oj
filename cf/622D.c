/*
f(i) = abs((n - i) * Di - (n - i)^2)
s = sigma i from [1, n] : f(i)
best Di = n - i
Yi = Xi + Di
   = Xi + n - i

let n = 10
D1 = 9
D2 = 8
D3 = 7
D4 = 6
D5 = 5
D6 = 4
D7 = 3
D8 = 2
D9 = 1
D10 = 0 <- impossible, but f(n) = 0 anyway

9 9
9 9      8 10 8
7 9 9 7      8 10 8
7 9 9 7      6 8 10 8 6
.
.
.
1 3  5 7 9 9 7 5 3  1      2  4 6 8 10 8 6 4 2

n = 13 ?
D8= 5
D9 =4
D10=3
D11=2
D12=1
D13=0

8 10 12 12 10 8     9 11 13 11 9
*/
#include <stdio.h>
int main(void)
{
    int n, b, i;
    scanf("%d", &n);
    for (b = 1; b <= 2; b++) {
        for (i = b; i <= n; i += 2)
            printf("%d ", i);
        i -= 2;
        for (i = i == n ? n - 2 : i; i >= b; i -= 2)
            printf("%d ", i);
    }
    printf("%d\n", n);

    return 0;
}

