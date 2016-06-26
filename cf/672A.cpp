#include <cstdio>
#include <sstream>
using namespace std;
int main()
{
    int n;
    stringstream ss;
    scanf("%d", &n);
    for (int i = 1; ss.str().size() < n; ++i)
        ss << i;
    printf("%c\n", ss.str()[n-1]);
}
