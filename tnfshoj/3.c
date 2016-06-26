#include <stdio.h>
int getInt(void) {static int i; return scanf("%d", &i) == 1 ? i : -1;}
int printInt(int i) {return !(printf("%d\n", i) > 0);}
int gcd(int a, int b) {return b ? gcd(b, a % b) : a;}
int solve(int t) {return t > 0 ? printInt(gcd(getInt(), getInt())) || solve(t - 1) : t;}
int main(void) {return solve(getInt());}
