#include <cstdio>
#define MAXN 31630
#define PN 3500
#define F(type, var, begin, end) \
        for(type var = (begin); var != (end); var++)
using namespace std;

bool sieve[MAXN] = {0};
int p[PN];
int pn = 0;

void linear_sieve()
{
    sieve[0] = sieve[1] = true;
    for (int i = 2; i < MAXN; ++i) {
       if (!sieve[i]) p[pn++] = i;
       for (int j = 0; (i * p[j]) < MAXN && j < pn; j++) {
            sieve[i *p[j]] = true;
            if ( (i % p[j]) == 0 ) break;
       }

    }
}
/*
void test_table()
{
    for (int i = 0;i<10;i++ ) {
        printf("sieve[%d]=%c\n",i,(sieve[i])?'t':'f');
        
    }
    printf("pn=%d\n", pn);
    for (int i = 0; i < pn; ++i) {
        printf("p[%d]=%d\n", i, p[i]);
    }
}
*/
int divisor(int a)
{
    if (a < MAXN && !sieve[a]) return 2;

    int r = 1;
    for (int i = 0; i < pn && (p[i] * p[i]) <= a; i++) {
        int pow = 0;
        while ((a % p[i]) == 0) {
            a /= p[i];
            pow++;
        }
        r *= (pow+1);
    }
    if (a != 1) r<<=1;

    return r;
}

int main (void)
{
    linear_sieve();
//    test_table();
    int n,L,U;
    scanf("%d", &n);
    while(n--) {
        scanf("%d%d", &L, &U);
        int num,maxd=0;
        for (int i = L; i <= U; i++) {
            int d = divisor(i);
            if (d > maxd) {
                maxd = d;
                num = i;
            }
        }

        printf("Between %d and %d, %d has a maximum of %d divisors.\n", 
                         L,     U, num,                maxd
        );
    }
    return 0;
}
