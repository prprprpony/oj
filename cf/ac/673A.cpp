#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
	int n;
	cin >> n;
	int cur = 0, t;
	for (int i = 0; i < n; ++i) {
		cin >> t;
		if (t - cur - 1 >= 15) {
			cur += 15;
			break;
		} else {
			cur = t;
		}
	}
	cout << (cur != t ? cur : min(90, cur + 15)) << '\n';
	return 0;
}