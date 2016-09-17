#include <iostream>
#include <string>
#include <vector>
using namespace std;
const int maxn = 100;
bool seive[maxn+1];
vector<int> p;
int main()
{
	seive[0] = seive[1] = true;
	for (int i = 2; i <= maxn; ++i) {
		if (!seive[i])
			p.push_back(i);
		for (int j : p) {
			if (i * j > maxn)
				break;
			seive[i * j] = true;
			if (i % j == 0)
				break;
		}
	}


	string s;
	int cnt = 0;
	int i;
	int last;
	for (i = 0; i < p.size() && p[i] * p[i] <= maxn && cnt <= 1; ++i) {
		cout << p[i] << endl;
		cin >> s;
		if (s == "yes") {
			++cnt;
			last = p[i];
			cout << p[i] * p[i] << endl;
			cin >> s;
			if (s == "yes")
				++cnt;
		}
	}
	if (!cnt)
		cout << "prime" << endl;
	else if (cnt > 1)
		cout << "composite" << endl;
	else {
		for ( ; i < p.size(); ++i) {
			if (p[i] * last > maxn) {
				cout << "prime" << endl;
				break;
			}
			cout << p[i] << endl;
			cin >> s;
			if (s == "yes") {
				cout << "composite" << endl;
				break;
			}
		}
	}
}
