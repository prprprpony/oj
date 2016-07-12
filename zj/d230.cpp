#include <iostream>
using namespace std;
const int M = 1e7;
const int maxn = 5001;
int dp[maxn];
int two[maxn];
inline int add(int a, int b) {return (a += b) >= M ? a - M : a;}
inline int mul(int a, int b) {return a * 1LL * b % M;}
int main()
{
    dp[0] = 1;
    two[0] = 1;
    for (int i = 1; i < maxn; ++i) {
        for (int j = 0; j < i; ++j)
            dp[i] = add(dp[i], mul(dp[j], two[i - j - 1]));
        for (int j = 0; j <= i; ++j)
            two[i] = add(two[i], mul(dp[j], dp[i - j]));
    }
    int n;
    while (cin >> n)
        cout << dp[n] << '\n';
}
