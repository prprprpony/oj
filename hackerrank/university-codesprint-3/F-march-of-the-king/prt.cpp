#include<cstdio>
#define REP(i,a,b) for (int i(a); i < (b); ++i)
#define RP(i,n) REP(i,0,n)
int main() {
const int W = 16;
puts("switch (c % W) {");
for (int i = W-1; i; --i)
	printf("case %d: ans += !(u & (*it++));\n", i);
puts("}");
puts("while (n--) {");
for (int i = 0; i < W; ++i)
	puts("ans += !(u & (*it++));");
puts("}");
}
