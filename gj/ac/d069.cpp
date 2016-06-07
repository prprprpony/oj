#include <cstdio>
#include <algorithm>
using namespace std;
const char c[][4] = {"甲", "乙", "丙"};
int main()
{
    pair<int, int> v[3];
    for (int i = 0; i < 3; ++i) {
        scanf("%d", &v[i].first);
        v[i].second = i;
    }
    sort(v, v + 3);
    puts(c[v[0].first + v[1].first > v[2].first ? v[1].second : v[2].second]);
}
