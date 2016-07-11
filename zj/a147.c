int scanf(const char *, ...);
int printf(const char *, ...);
int putchar(int);
int getint(int new) {static int x; return (new && scanf("%d", &x) == 1 && 0) | x;}
int printall(int n) {return n && printall(n - 1) || (n % 7 && (n - 1 && !putchar(' ') || printf("%d", n) < 1));}
int solve(void) {return getint(1) && (printall(getint(0) - 1) || !putchar('\n') || solve());}
int main(void) {return solve();}
