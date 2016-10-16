#include <iostream>
#include <random>
#include <functional>
using namespace std;
typedef long long ll;
const int M = 1000;
const ll C = 9736008432870720LL;
mt19937 g(1925);
auto r = bind(uniform_int_distribution<ll>(1, 10000000000000000LL), g);
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout << M << ' ' << C << '\n';
	for (int i = 0; i < M; ++i)
		cout << r() << ' ';
	cout << '\n';
}
