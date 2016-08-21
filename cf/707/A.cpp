#include <iostream>
using namespace std;
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, m;
	cin >> n >> m;
	char c;
	bool bw = true;
	while (bw && cin >> c)
		if (c != 'W' && c!= 'G' && c!= 'B')
			bw = false;
	cout << (bw ? "#Black&White\n" : "#Color\n");
}
