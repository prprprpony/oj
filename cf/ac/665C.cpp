#include <cstdio>
using namespace std;
const int maxn = 2e5 + 111;
char s[maxn];
int main()
{
    gets(s);
    for (int i = 1; s[i]; ++i) {
        if (s[i] == s[i-1]) {
            for (char c = 'a'; c <= 'z'; ++c)
                if (c != s[i] && c != s[i+1]) {
                    s[i] = c;
                    break;
                }
        }
    }
    puts(s);
    
    return 0;
}
