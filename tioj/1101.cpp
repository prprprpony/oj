#include<cstdio>
#include<cctype>
using namespace std;
struct pii
{
    pii() {}
    pii(int a,int b) : F(a), S(b) {}
    int F,S;
};
pii operator + (const pii & a,const pii & b) {return pii(a.F+b.F,a.S+b.S);}
int gc()
{
    static char buf[16];
    static size_t ptr, sz;
    if (ptr == sz) {
        sz = fread(buf,1,sizeof buf,stdin);
        ptr = 0;
    }
    if (ptr == sz)
        return -1;
    return buf[ptr++];
}
int rit()
{
    int a=0,c;
    while (!isdigit(c=gc()));
    do {
        a = 10 * a + c - '0';
    } while (isdigit(c=gc()));
    return a;
}
void wit(int a)
{
    static char buf[12];
    int n = 0;
    do {
        buf[n++] = a%10+'0';
    } while (a/=10);
    buf[n] = 0;
    for (int i=0,j=n-1; i < j; ++i, --j) {
        buf[i] ^= buf[j];
        buf[j] ^= buf[i];
        buf[i] ^= buf[j];
    }
    fputs(buf,stdout);
}
int a,b,k,i;
pii la[2],dp;
int main()
{
    while (a = rit(), b = rit()) {
        if (a == 1) {
            fputs(b==1?"0/1\n":"1/0\n",stdout);
            continue;
        }
        la[0] = pii(1,0);
        la[1] = pii(0,1);
        a -= 2;
        k = (1<<a)+b-1;
        for (i = a; i >= 0; --i) {
            dp = la[0] + la[1];
            if (i && (k>>(i-1)&1))
                la[1] = dp;
            else
                la[0] = dp;
        }
        wit(dp.F);
        putchar('/');
        wit(dp.S);
        putchar('\n');
    }
}
