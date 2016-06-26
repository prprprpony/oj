#include <iostream>
#include <vector>
using namespace std;
const long long maxp = 1e6 + 5;
vector<long long> p;
vector<bool> isp(maxp, true);
void build_table()
{
    isp[0] = isp[1] = false;
    for (long long i = 2; i < maxp; i++) {
        if (isp[i])
            p.push_back(i);
        for (vector<long long>::iterator it = p.begin(); it != p.end() && (*it) * i < maxp; it++) {
            isp[(*it) * i] = false;
            if (i % (*it) == 0)
                break;
        }
    }
}
int f(long long x)
{
    int ans = 1;
    for (vector<long long>::iterator it = p.begin(); it != p.end() && x != 1 && (*it) * (*it) <= x; it++) {
        int power = 0;
        while (x % (*it) == 0) {
            x /= *it;
            power++;
        }
        ans *= power + 1;
    }
    if (x > 1)
        ans *= 2;
    return ans;
}
int main()
{
    int t;
    long long a, b;
    build_table();
    cin >> t;
    while (t--) {
        cin >> a >> b;
        cout << f(a * b) << '\n';
    }
    return 0;
}
